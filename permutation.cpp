#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<vector<int>> permutation(vector<int>& nums){
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		// res.push_back(nums);
		// int ss=nums.size();
		dfs(res, nums, 0);
		return res;
	}

	void dfs(vector<vector<int>>& res, vector<int>& nums, int start){
		int ss=nums.size();
		if(start==ss){
			res.push_back(nums);
			return;
		}
		int i=start; 
		for(; i<ss; ++i){
			swap(nums[i], nums[start]);
			dfs(res, nums, i+1);
			swap(nums[start], nums[i]);
			if(nums[i]==nums[i+1] && i<ss){
				i++;
			}
		}

	}
};

int main()
{	
	Solution ss;
	vector<int> nums = {1,2,3};
	vector<vector<int>> res;
	res=ss.permutation(nums);
	int si=res.size();
	for(int i=0; i<si; ++i){
		for(auto it : res[i]){
			cout<<it<<" ";
		}
		cout<<endl;
	}
	/* code */
	return 0;
}