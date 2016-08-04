#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class ValidRoman
{
public:
	bool validRoman(string& roman){
		if(roman.length()==1) return true;
		int l=roman.length();
		for(int i=0; i<l-1; ++i){
			if(to_Arab(roman[i])>= to_Arab(roman[i+1]) || 5*to_Arab(roman[i])==to_Arab(roman[i+1]) ||
				10*to_Arab(roman[i])==to_Arab(roman[i+1])){
				continue;
			}else{
				return false;
			}
		}
		return true;
	}

	int to_Arab(char C){
		unordered_map<char, int> mymap;
		mymap['M']=1000;
		mymap['D']=500;
		mymap['C']=100;
		mymap['L']=50;
		mymap['X']=10;
		mymap['V']=5;
		mymap['I']=1;
		int res=mymap[C];
		return res;
	}
	
};

int main(){
	ValidRoman V;
	bool res;
	string roman="VII";
	res=V.validRoman(roman);
	cout<<res<<endl;
	return 0;
}