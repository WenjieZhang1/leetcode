#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
	int compare(string version1, string version2){
		int s1=version1.length();
		int s2=version2.length();
		int l1=0;
		int l2=0;
		while(l1<s1 || l2<s2){
			int val1=0;
			int val2=0;
			while(l1<s1){
				if(version1[l1]=='.'){
					l1++;
					break;
				}
				val1=val1*10+(version1[l1]-'0');
				l1++;
			}
			while(l2<s2){
				if(version2[l2]=='.'){
					l2++;
					break;
				}
				val2=val2*10+(version2[l2]-'0');
				l2++;
			}
			if(val1>val2) return 1;
			if(val1<val2) return -1;
		}
		return 0;
	}
	
};

int main(){
	Solution ss;
	string version1="1.15";
	string version2="1.2";
	int res;
	res=ss.compare(version1,version2);
	cout<<res<<endl;
	return 0;
}