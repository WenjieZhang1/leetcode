#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
	string generatevalid(string& s){
		int len=s.length();
		int leftcount=0;
		for(int i=0; i<len; ++i){
			if(s[i]=='('){
				leftcount++;
			}else if(s[i]==')' && leftcount==0){
				s.erase(i,1);
			}else if(s[i]==')'){
				leftcount--;
			}else{
				continue;
			}
		}

		int newlen=s.length();
		int rightcount=0;
		for(int i=newlen-1; i>=0; --i){
			if(s[i]==')'){
				rightcount++;
			}else if(s[i]=='(' && rightcount==0){
				s.erase(i,1);
			}else if(s[i]=='('){
				rightcount--;
			}else{
				continue;
			}
		}

		return s;

	}
	
};

int main(){
	Solution ss;
	string s="((（a3sq)）";
	string res;
	res=ss.generatevalid(s);
	cout<<res<<endl;
	return 0;
}