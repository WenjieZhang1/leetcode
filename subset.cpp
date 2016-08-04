#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
	vector<vector<int>> subsets(vector<int> nums){
		vector<vector<int>> res;
		vector<int> temp;
		res.push_back(temp);
		int ss=nums.size();
		if(ss==0) return res;
		sort(nums.begin(), nums.end());
		for(int i=1; i<=ss; ++i){
			temp.clear();
			dfs(res, temp, nums, 0, i);
		}
		return res;
	}
	void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int start, int range){
		int ss=nums.size();
		int ts=temp.size();
		if(ts==range){
			res.push_back(temp);
			return;
		}
		for(int i=start; i<ss; ++i){
			temp.push_back(nums[i]);
			dfs(res, temp, nums, i+1, range);
			temp.pop_back();
		}
	}
};
int main(){
	Solution so;
	vector<int> S={5,1,3,2};
	vector<vector<int>> res;
	res=so.subsets(S);
	int si=res.size();
	for(int i=0; i<si; ++i){
		int si1=res[i].size();
		for(int j=0; j<si1; ++j){
			cout<<res[i][j];
		}
		cout<<endl;
	}
}