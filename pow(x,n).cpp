#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	double pow(double x, int n){
		if(x==0) return 0;
		if(n==0) return 1;
		bool flag = (n < 0) ? 1 : 0;
		double res = pow (x, n/2);
		res=res*res;
		if(n%2){
			res=res*x;
		} 
		return (flag==0) ? res : (1/res);
	}
};

int main(){
	double x=3.5;
	int n=2;
	Solution ss;
	double res = ss.pow(x, n);
	cout<<res<<endl;
	return 0;
}