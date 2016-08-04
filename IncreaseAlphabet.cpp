#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
	string increaseA(string input, int value){
		int ss=input.length();
		string res="";
		if(ss==0) return res;
		for(int i=0; i<ss; ++i){
			res+=(input[i]+value);
		}
		return res;
	}
	
};

int main(){
	Solution ss;
	string input="aAa";
	int value=3;
	string res;
	res=ss.increaseA(input, value);
	cout<<res<<endl;
	return 0;
}