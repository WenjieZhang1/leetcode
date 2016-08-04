#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        string temp="";
        dfs(s, res, temp, 0);
        return res;
    }
    
    void dfs(string s, vector<string>& res, string &temp, int start){
    	int len=s.length();
        if(start==len){
            if(ispalin(temp)){
                res.push_back(temp);
                return;
            }
        }
        int i=start;
        for(; i<len; ++i){
            temp+=s[i];
            dfs(s, res, temp, i+1);
            temp.pop_back();
        }
    }
    
    bool ispalin(string s){
        int len=s.length();
        int start=0;
        int end=len-1;
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};



int main(){
	vector<string> res;
	Solution ss;
	string s="aabb";
	res=ss.generatePalindromes(s);
	for(auto it : res){
		cout<<it<<" ";

	}
	cout<<'\n';
	return 0;
}