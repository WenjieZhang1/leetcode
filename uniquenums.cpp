#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
	vector<int> uniquenums(vector<int> &nums){
		unordered_map<int,int> mymap;
		int ss=nums.size();
		for(int i=0; i<ss; ++i){
			if(mymap.find(nums[i])!=mymap.end()){
				mymap[nums[i]]--;
			}else{
				mymap[nums[i]]++;
			}
		}
		std::vector<int> res;
		for(auto it : mymap){
			if(it.second>0){
				res.push_back(it.first);
			}
		}
		return res;
	}
	
};


int main(){
	Solution ss;
	std::vector<int> nums={1,9,4,5,8,3,1,3,5,9};
	vector<int> res;
	res=ss.uniquenums(nums);
	for(auto it : res){
		cout<<it<<" ";
	}
	cout<<'\n';
	return 0;
}