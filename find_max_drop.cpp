#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#define random(x) (rand()%x)
using namespace std;

class Solution 
{
public:
int max_drop(vector<int>& nums){
	int s=nums.size();
	int max=nums[0];
	int drop=0;
	for(int i=1; i<s; ++i){
		if(nums[i]>max){
			max=nums[i];
		}else{
			if(max-nums[i]>drop){
				drop=max-nums[i];
			}
		}
	}
	return drop;
}
	
};

int main(){
	Solution ss;
	vector<int> nums={1,10,2,3, 28, -1};
	int res;
	res=ss.max_drop(nums);
	cout<<res;
	return 0;
}