#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	bool checksub(vector<int>& nums, int target){
		int s=nums.size();
		if(s==0) return false;
		if(s==1) return nums[0]==target;
		int sum=0;
		int start=0;
		for(int i=0; i<s; ++i){
			sum+=nums[i];
			if(sum==target) return true;
			while(sum>target){
				sum-=nums[start];
				start++;
				if(sum==target){
					return true;
				}
			}
		}
		return false;
	}


	
};

int main(){
	Solution ss;
	vector<int> nums={1,2,2,4,5,6,8};
	int target=21;
	bool res;
	res=ss.checksub(nums, target);
	cout<<res<<endl;
	return 0;
}