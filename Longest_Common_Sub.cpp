#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
#include <string>
#define random(x) (rand()%x)
using namespace std;
class Solution
{
public:
	string Longest_Common_Sub(string& l1, string& l2){
		int s1=l1.length();
		int s2=l2.length();
		vector<vector<int>> record(s1+1, vector<int>(s2+1, 0));
		for(int i=1; i<=s1; ++i){
			for(int j=1; j<=s2; ++j){
				if(l1[i]==l2[j]){
					record[i][j]=record[i-1][j-1]+1;
				}else{
					record[i][j]=0;
				}
			}
		}
		int maxlen=0;
		int pos=0;
		for(int i=1; i<=s1; ++i){
			for(int j=1; j<=s2; ++j){
				if(maxlen<record[i][j]){
					maxlen=record[i][j];
					pos=i;
				}
			}
		}
		string res=l1.substr(pos-maxlen+1, maxlen);
		return res;
	}
	
};

int main(){
	Solution ss;
	string l1="abbcacb";
	string l2="cabcacs";
	string res;
	res=ss.Longest_Common_Sub(l1, l2);
	cout<<res;
	return 0;
}