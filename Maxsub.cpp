#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int maxsum(vector<int> &nums){
		int max=0;
		int sum=0;
		int ss=nums.size();
		for(int i=0; i<ss; ++i){
			sum+=nums[i];
			if(sum>max) max=sum;
			if(sum<0) sum=0;
		}
		return max;
	}
};

int main(){
	Solution ss;
	vector<int> nums={1,2,3,5,6,-7,2,1};
	int res=ss.maxsum(nums);
	cout<<res<<'\n';
	return 0;
}