#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int findpeek(vector<int>& nums){
		int s=nums.size();
		if(s<3){
			return 0;
		}
		bool as=(nums[1]-nums[0]>0);
		if(as){
			return (nums[s-1]+nums[0]+s-1)/2;
		}else{
			return (nums[0]+nums[s-1]-s+1)/2;
		}
	}
	
};

int main(){
	Solution ss;
	int res;
	vector<int> nums={2,3,4,5,6,5,4,3};
	res=ss.findpeek(nums);
	cout<<res<<endl;
	return 0;
}