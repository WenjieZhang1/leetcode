#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
	int removeduplicate(vector<int> &nums){
		int len=nums.size();
		unordered_set<int> myset;
		if(len<2) return len;
		int res=0;
		for(int i=0; i<len; ++i){
			if(myset.find(nums[i])==myset.end()){
				nums[res++]=nums[i];
				myset.insert(nums[i]);
			}
		}
		return res;
	}
	
};

int main(){
	Solution ss;
	vector<int> nums={1,2,3,3,4,5,6,7,7};
	int res;
	res=ss.removeduplicate(nums);
	cout<<res<<endl;
	return 0;
}