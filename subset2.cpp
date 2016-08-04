#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        // write your code here
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        sort(S.begin(), S.end());
        int ss=S.size();
        if(ss==0){
            return res;
        }
        for(int i=1; i<=ss; ++i){
            temp.clear();
            dfs(res, temp, S, 0, i);
        }
        return res;
    }
    void dfs (vector<vector<int>> &res, vector<int> &temp, vector<int> &S, int start, int range){
    	int Si=S.size();
    	int ts=temp.size();
        if(ts==range){
            res.push_back(temp);
            return;
        }
        int i=start;
        while(i<Si){
			temp.push_back(S[i]);
            dfs(res,temp,S,i+1,range);
            temp.pop_back();
            i++;
            while(i<Si && S[i]==S[i-1]){
        		i++;
        	}
        }
    }
};

int main(){
	Solution so;
	vector<int> S={5,5,5,5,5};
	vector<vector<int>> res;
	res=so.subsetsWithDup(S);
	int si=res.size();
	for(int i=0; i<si; ++i){
		int si1=res[i].size();
		for(int j=0; j<si1; ++j){
			cout<<res[i][j];
		}
		cout<<endl;
	}
}