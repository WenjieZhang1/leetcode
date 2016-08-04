#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
public: 
	string kpermutation(int n, long k){
		vector<int> num(n, 0);
		int count=1;
		for(int i=0; i<n; ++i){
			num[i]=i;
			count*=(i+1);
		}
		
		string res="";
		for(int i=0; i<n; ++i){
			count=count/(n-i);
			long x=k/count;
			res+=(num[x]+'0');
			for(int j=x; j<n-1-i; ++j){
				num[j]=num[j+1];
			}
			k=k%count;
		}
		return res;
	}
};

int main(){
	Solution ss;
	int n=3; 
	int k=4;
	string res;
	res=ss.kpermutation(n, k);
	cout<<res<<endl;
	return 0;
}
