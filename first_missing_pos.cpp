#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int findpos(vector<int> &nums){
		int ss=nums.size();
		for(int i=0; i<ss; ++i){
			while(nums[i]>0 && nums[nums[i]-1]!=nums[i] && nums[i]<ss) swap(nums, nums[i]-1, i);
		}
		for(int i=0; i<ss; ++i){
			if(nums[i]!=i+1){
				return i+1;
			}
		}
		return ss+1;
	}

	void swap(vector<int>& nums, int i, int k){
		int temp=nums[i];
		nums[i]=nums[k];
		nums[k]=temp;
	}
};

int main(){
	Solution ss;
	int res;
	vector<int> nums={-1,2,4,5,6};
	res=ss.findpos(nums);
	char x='1';
	char w=x+3;
	cout<<w<<'\n';
	cout<<res<<'\n';
	return 0;
}

