#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
void SWAP(int a, int b, unsigned int *v, unsigned int *w) { 
		unsigned int tmp = v[a]; 
		v[a] = v[b]; 
		v[b] = tmp; 
		tmp = w[a]; 
		w[a] = w[b]; 
		w[b] = tmp; 
}
int qselect(unsigned int *v, unsigned int* w, int len, int k)
{
	int i, st;
	// u tmp; 
 
	for (st = i = 0; i < len - 1; i++) {
		if (v[i] > v[len-1]) continue;
		SWAP(i, st, v, w);
		st++;
	}
 
	SWAP(len-1, st, v, w);
 
	return k == st	?v[st]
			:st > k	? qselect(v, w, st, k)
				: qselect(v + st, w + st, len - st, k - st);
}
 
int main(void)
{
#	define N (sizeof(x)/sizeof(x[0]))
	int x[] = {10, 8, 9, 6, 5, 0, 1, 2, 3, 4};
	int y[] = {9, 8, 7, 6, 5, 0, 1, 2, 3, 4};
	unsigned int X[N];
	unsigned int Y[N];
	memcpy(X, x, sizeof(x)); // qselect modifies array

	memcpy(Y, y, sizeof(y)); // qselect modifies array

 	int q = qselect(X+1, Y+1, 9, 5);
 	cout<< "the K is " << q << endl;
 	for (int i = 0; i < 10; i++){
 		printf("%u\n", *(X+i));
 	}
 	printf("1111");
 	cout<<endl;
 	for (int i = 0; i < 10; i++){
 		printf("%u\n", *(Y+i));
 	}
	return 0;
}