#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	void Wigglesort(vector<int>& nums){
		int ss=nums.size();
		if(ss==0 || ss==1) return;
		for(int i=0; i<ss-1; ++i){
			if(i%2==0){
				if(nums[i]>nums[i+1]){
					swap(nums[i], nums[i+1]);
				}
			}else{
				if(nums[i]<nums[i+1]){
					swap(nums[i],nums[i+1]);
				}
			}
		}
	}
	
};

int main(){
	vector<int> nums = {1,2,2,1,2,1,1,1,1,2,2,2};
	Solution ss;
	ss.Wigglesort(nums);
	for(auto it : nums){
		cout<<it;
	}
	cout<<'\n';
	return 0;
}