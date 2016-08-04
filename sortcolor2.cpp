// Naive algorithm for building suffix array of a given text
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class  Solution
{
public:
void sortcolor2(vector<int>& nums, int k){
		int cout=0;
		int start=0;
		int end=nums.size()-1;
		while(cout<k){
			int min1=nums[start];
			int max1=nums[start];
			for(int i=start; i<=end; ++i){
				min1=min(min1, nums[i]);
				max1=max(max1, nums[i]);
			}
		int left=start;
		int right=end;
		int cur=left;
		while(cur<=right){
			if(nums[cur]==min1){
				swap(nums[cur++], nums[left++]);
			}else if(nums[cur]>min1 && nums[cur]<max1){
				cur++;
			}else{
				swap(nums[cur++],nums[right--]);
			}
		}
		cout+=2;
		start=left;
		end=right;
		}

	}
	
};

int main(){
	Solution ss;
	vector<int> nums={0,1,2,3,0,2,1,3};
	int s=nums.size();
	ss.sortcolor2(nums, s);

	for(int i=0; i<s; ++i){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	return 0;
}