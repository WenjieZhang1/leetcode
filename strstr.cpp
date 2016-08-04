#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class  Solution
{
public:
	bool hasstrstr(string& s1, string& s2){
		int l1=s1.length();
		int l2=s2.length();
		if(l1<l2) return false;
		sort(s2.begin(), s2.end());
		for(int i=0; i<l1-l2+1; i++){
			string temp=s1.substr(i, l2);
			cout<<temp<<endl;
			sort(temp.begin(), temp.end());
			if(temp==s2){
				return true;
			}
		}
		return false;
	}
};

int main(){
	Solution ss;
	bool res;
	string s1="hello";
	string s2="ol";
	res=ss.hasstrstr(s1,s2);
	cout<<res<<endl;
	return 0;
}