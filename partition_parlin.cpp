#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<vector<string>> partion(string &S){
		int slen=S.length();
		vector<vector<string>> res;
		if(slen==0) return res; 
		vector<string> path;
		dfs(res, path, S, 0);
		return res;

	}

	void dfs(vector<vector<string>>& res, vector<string>& path, string& S, int start){
		int ss=S.length();
		if(start==ss){
			res.push_back(path);
			return; 
		}
		for(int i=start; i<ss; ++i){
			string temp = S.substr(start, i-start+1);
			if(isValid(temp)){
				path.push_back(temp);
				dfs(res, path, S, i+1);
				path.pop_back();
			}
		}
	}

	bool isValid(string &s){
		int ss=s.length();
		int i=0;
		int j=ss-1;
		while(i<=j){
			if(s[i++]!=s[j--]){
				return false;
			}
		}
		return true;
	}
	
};

int main(){
	Solution ss;
	vector<vector<string>> res;
	string S="aab";
	res=ss.partion(S);
	int si=res.size();
	for(int i=0; i<si; ++i){
		for(auto it : res[i]){
			cout<<it<<" ";
		}
		cout<<'\n';
	}

	return 0;
}