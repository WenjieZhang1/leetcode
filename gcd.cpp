# include <iostream>
using namespace std;
int gcd (int a, int b)
{
	int remain=0;
	while (b != 0)
	{
		remain= a % b;
		a=b;
		b=remain;
	}
	return a;
}
