#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<vector<int>> combination(vector<int> &nums, int target){
		vector<vector<int>> res;
		vector<int> temp;
		int ss=nums.size();
		if(ss==0) return res;
		sort(nums.begin(), nums.end());
		int sum=0;
		dfs(res, temp, nums, target, 0, sum);
		return res;
	}

	void dfs(vector<vector<int>>& res, vector<int> &temp, vector<int>& nums, int target, int start, int &sum){
		if(sum==target){
			res.push_back(temp);
			return;
		}
		if(sum>target){
			return;
		}
		int ss=nums.size();
		for(int i=start; i < ss; ++i){
			temp.push_back(nums[i]);
			sum+=nums[i];
			dfs(res, temp, nums, target, start+1, sum);
			sum-=nums[i];
			temp.pop_back();
		}
	}
	
};

int main(){
	vector<int> nums{1,2,4,5,6,3};
	int target=7;
	Solution ss;
	vector<vector<int>> res;
	res=ss.combination(nums, target);
	int si=res.size();
	for(int i=0; i<si; ++i){
		for(auto it : res[i]){
			cout<<it<<" ";
		}
		cout<<'\n';
	}

	return 0;
}