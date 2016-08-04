#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void wiggleSort(vector<int>& nums) {
        int ss=nums.size();
        vector<int> temp(ss, 0);
        sort(nums.begin(), nums.end());
        int start=(ss+1)/2;
        int tail=ss;
        for(int i=0; i<ss; ++i){
            temp[i]=(i%2==0) ? nums[--tail] : nums[--start];
        }
        for(int i=0; i<ss; ++i){
            nums[i]=temp[i];
        }
        reverse(nums.begin(), nums.end());
    }
};

int main(){
	Solution ss;
	vector<int> nums={1, 5, 1, 1, 6, 4};
	ss.wiggleSort(nums);
	for(auto it : nums){
		cout<<it<<" ";
	}
	return 0;
}