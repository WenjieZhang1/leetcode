#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
       auto start=s.begin();
       auto it=s.begin();
       for(; it!=s.end(); ++it){
           if(it!=s.end() && *it==' '){
               reverse(start, it);
               start=it++;
           }
       }
       reverse(start, s.end());
       reverse(s.begin(), s.end());
       
    }

};


int main(){
	string s="the sky is blue";
	Solution ss;
	ss.reverseWords(s);
	cout<<s<<endl;
	string w="asvdsd";
	w=w.substr(2);
	cout<<w<<endl;

	return 0;
}