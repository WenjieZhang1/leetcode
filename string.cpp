# include <iostream>
# include <string>
# include <vector>;
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    	int leng=strs.size();
        if(leng==0) return "";
        if(leng==1) return strs[0];
        string prefix=strs[0];
        for(int i=1; i<leng; i++){
            if(prefix=="" || strs[i]=="") return "";
            int len=prefix.length() < strs[i].length() ? prefix.length() : strs[i].length();
            int j=0;
            for(; j<len; j++){
                if(prefix[j] != strs[i][j]) break;
                
            }
            prefix=prefix.substr(0,j);
        }
        return prefix;
    }
int main(){
   vector<string> n(1,"");
   int q=n.size();
   n.pop_back();
   cout<<n[0]<<'\n';
   cout<<q<<endl;
   string s="asdfdf";
   string w=s.substr(1);
   cout<<w<<'\n';

   return 0;
}