// Naive algorithm for building suffix array of a given text
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int removefromun(vector<int>& nums){
		unordered_set<int> myset;
		int res=1;
		int ss=nums.size();
		if(ss<2) return ss;
		for(int i=1; i<ss; ++i){
			if(myset.find(nums[i])==myset.end()){
				nums[res++]=nums[i];
				myset.insert(nums[i]);
			}else{
				continue;
			}
		}
		for(auto it : nums){
			cout<<it<<" ";
		}
		cout<<endl;
		return res;
	}
	
};

int main(){
	Solution ss;
	vector<int> nums={1,3,2,4,5,2,7,5};
	int res=0;
	res=ss.removefromun(nums);
	cout<<res;
	return 0;
}