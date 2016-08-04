# include <iostream>
# include <vector>
using namespace std;

int gcd (int a, int b)
{
	while (b!= 0)
	{
		int rem = a% b;
		a=b;
		b=rem;
	}
	return a;
}

double coprimeproximate(int n)
{

	int totalcount=0; int primecount=0;
	for( int i=1; i <= n; i++)
	{
		for (int j=i+1; j <= n; j++)
		{
			totalcount++;
			if ( gcd (i, j)==1 )
				primecount++;
		}

	}
	return  (double) primecount/totalcount;
}

int main ()
{   vector<int> ss={1,2,3,4};
	auto it = ss.begin();
	ss.erase(it);
	for(auto x : ss){
		cout<<x<<endl;
	}

	return 0;
}
