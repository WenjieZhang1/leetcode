#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int compare_int(unsigned int v, unsigned int w) {
        if (v < w) {
            return 1;
        }else{
            return 0;
        }
}

void exchange(unsigned int *v, int lo, int hi) {
    unsigned int temp = *(v+lo);
    *(v+lo) = *(v+hi);
    *(v+hi) = temp;
}
unsigned int partition(unsigned int *v, int lo, int hi, unsigned int *w) {

        int i = lo;
        int j = hi + 1;
        while(1) {
            while(i < hi && compare_int(*(v+(++i)), *(v+lo)));
            while(j > lo && compare_int(*(v+lo), *(v+(--j))));
            if(i >= j) {
                break;
            }
            exchange(v, i, j);
            exchange(w, i, j);
        }
        exchange(v, lo, j);
        exchange(w, lo, j);
        return j;
    }

unsigned int find_kth(unsigned int *v, int n, int k, unsigned int *w) {
        int lo = 0;
        int hi = n;
        while (lo < hi) {
            int j = partition(v, lo, hi, w);
            if(j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }
        return *(v+k);
}

int main(){
	unsigned int a[10] = {1,3,5,4,6,8,7,2,10,9};
	unsigned int b[10] = {1,3,5,4,6,8,7,2,10,9};
	unsigned int x = find_kth(a[0], 10, 5, b[0]);
	printf(x);
	return 0;
}