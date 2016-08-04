#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int findk(vector<int> &nums, int k){
		int ss=nums.size();
		int left=0;
		int right=ss-1;
		while(true){
			int pivot=partition(nums, left, right);
			if(pivot==k-1) return nums[pivot];
			if(k-1<pivot) right=pivot-1;
			else left=pivot+1;
		}

	}

	int partition(vector<int> &nums, int left, int right){
		int pivot=nums[left];
		int l=left+1;
		int r=right;
		while(l<=r){
			if(nums[l]<pivot && nums[r]>pivot){
				swap(nums[l++], nums[r--]);
			}
			if(nums[l]>=pivot){
				l++;
			}
			if(nums[r]<=pivot){
				r--;
			}
		}
		swap(nums[left], nums[r]);
		return r;

	}


	
};

int main(){
	Solution ss;
	int k=3;
	vector<int> nums={1,2,3,4,2,3};
	int res=ss.findk(nums, k);
	cout<<res<<'\n';
	return 0;
}