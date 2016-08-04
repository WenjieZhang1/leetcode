#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool containdu(vector<int>& nums){
		unordered_set<int> myset;
		int ss=nums.size();
		for(int i=0; i<ss; i++){
			if(myset.find(nums[i])!=myset.end()){
				return true;
			}
			myset.insert(nums[i]);
		}
		return false;
	}
	
};

int main(){
	Solution ss;
	vector<int> nums={1,2,3,4,5};
	bool res=ss.containdu(nums);
	cout<<res<<endl;
	return 0;
}