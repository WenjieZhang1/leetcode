#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
	vector<vector<int>> helper (int target, vector<int> nums){
		vector<vector<int>> res;
		unordered_set <int> myset;
		unordered_set <pair<int, int>> reset;
		int ss=nums.size();
		for(int i=0; i<ss; ++i){
			myset.insert(nums[i]);
		}
		for(int i=0; i<ss; ++i){
			int n1=target-nums[i];
			int n2=target+nums[i];
			if(myset.find(n1)!=myset.end()){
				pair<int, int> p = (nums[i] < n1) ? make_pair(nums[i], n1) : make_pair(n1, nums[i]);
				reset.insert(p);
			}
			if(myset.find(n2)!=myset.end()){
				pair<int, int> p = (nums[i]< n2) ? make_pair(nums[i], n2) : make_pair(n2, nums[i]);
				reset.insert(p);
			}
		}
		for(auto it : reset){
			vector<int> temp = {it.first, it.second};
			res.push_back(temp);
		}
		return res;
	}
};
int main(){

	return 0;
}