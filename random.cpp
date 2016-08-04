#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#define random(x) (rand()%x)
using namespace std;

class Solution{
public:
	int find_maxindex(vector<int>& nums){
		int max=nums[0];
		int max_index=0;
		int count=1;
		int ss=nums.size();
		for(int i=1; i<ss; ++i){
			if(max<nums[i]){
				max=nums[i];
				count=1;
				max_index=i;
			}
			if(max==nums[i]){
				count++;
				if(random(count) ==0){
					max_index=i;
				}
			}
		}
		return max_index;
	}
}; 



 int main(){
 	Solution sl;
 	vector<int> nums={2,4,4,6,3,1,6,6};
 	int res;
 	res=sl.find_maxindex(nums);
 	cout<<res<<endl;
 	res=sl.find_maxindex(nums);
 	cout<<res<<endl;
 	res=sl.find_maxindex(nums);
 	cout<<res<<endl;
 	res=sl.find_maxindex(nums);
 	cout<<res<<endl;
 	res=sl.find_maxindex(nums);
 	cout<<res<<endl;
 	 	res=sl.find_maxindex(nums);
 	cout<<res<<endl;
 	 	res=sl.find_maxindex(nums);
 	cout<<res<<endl;

 	 	res=sl.find_maxindex(nums);
 	cout<<res<<endl;
 	return 0;
 }