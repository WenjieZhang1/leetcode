# include <iostream>
# include <vector>
# include <string>
#include <cctype>
#include <algorithm>

using namespace std;
int main(){
     string s ="aASddfsdfF";
     transform(s.begin(), s.end(), s.begin(), ::tolower);
     char x='s';
     if(x==s[2]){
     	cout<<s[2];
     }
     

	return 0;

}