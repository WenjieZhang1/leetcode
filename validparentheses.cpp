#include <iostream> 
#include <string>
#include <stack>
using namespace std;
class Solution{
public:
    bool validParentheses(string &s){
        int ss=s.length();
        stack<char> st;
        for(int i=0; i<ss; ++i){
            if(s[i]==')' || s[i]=='>' || s[i]=='}' || s[i]==']'){
                if(st.empty()) return false;
                else{
                    char t=st.top();
                    st.pop();
                    if((t=='(' && s[i]!=')') || (t=='[' && s[i]!=']') 
                       || (t=='{' && s[i]!='}') || (t=='<' && s[i]!='>')){
                        return false;
                    }
                }
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};

int main(){
	Solution ss;
	string s;
	
	bool res=ss.validParentheses(s);
	cout<<res<<endl;
	return 0;
}