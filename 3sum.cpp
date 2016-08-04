#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<vector<int>> 3sum(vector<int> nums){
		vector<vector<int>> res;
		int s=nums.size();
		sort(nums.begin(), nums.end());
		if(s<3 || nums[0]>0 || nums[s-1]<0) return res;
		for(int i=0; i<s-2 && nums[i]<=0; ++i){
			int j=i+1;
			int k=s-1;
			while(j<k){
				if(nums[i]+nums[j]+nums[k]==0){
					vector<int> temp = {nums[i], nums[j], nums[k]};
					res.push_back(temp);
				while(j<s-1 && nums[j]=nums[j+1]) ++j;
				++j;
				while(k>j && nums[k]==nums[k-1]) --k;
				--k; 
				}else if(nums[i]+nums[j]+nums[k]<0){
					++j;
				}else{
					--k;
				}
			}
			while(i<s-2 && nums[i]==nums[i+1]) ++i;

		}
		return res;
	}
};