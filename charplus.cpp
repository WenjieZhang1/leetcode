#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
	string sum_str(string b,string c){
		int s1=b.length();
		int s2=c.length();
		string S="";
		int carry=0;
		int sum=0;
		while(s1>0 && s2>0){
			sum=(b[--s1]-'0')+(c[--s2]-'0')+carry;
			cout<<sum<<'\n';
			carry=sum/10;
			sum=sum%10;
			S+=(sum+'0');
		}
		while(s1>0){
			sum=(b[--s1]-'0')+carry;
			carry=sum/10;
			sum=sum%10;
			S+=(sum+'0');
		}
		while(s2>0){
			sum=(c[--s2]-'0')+carry;
			carry=sum/10;
			sum=sum%10;
			S+=(sum+'0');
		}
		cout<<S<<'\n';
		reverse(S.begin(), S.end());
		cout<<S<<'\n';
		return S;

	}
	
};


int main(){
	string b="123457374";
	string c="1216264363";
	string a;
	Solution ss;
	a=ss.sum_str(b, c);
	int x=5;
	char s=x+'0';
	cout<<s;

	return 0;
}