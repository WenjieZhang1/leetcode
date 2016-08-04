// Naive algorithm for building suffix array of a given text
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int taskschedule(vector<int> nums, int interval){
		int ss=nums.size();
		if(ss==0) return 0;
		int ret=0;
		unordered_map<int, int> mymap;
		for(int i=0; i<ss; ++i){
			if(mymap.find(nums[i])==mymap.end() || mymap[nums[i]]<=ret){
				ret++;
			}else{
				ret=mymap[nums[i]];
			}
			mymap[nums[i]]=ret+interval+1;
		}
		return ret;
	}


	int followup(vector<int>& nums, int interval){
		int ss=nums.size();
		if(ss<2) return ss;
		unordered_map<int, int> mymap;
		for(auto it : nums){
			mymap[it]++;
		}
		int countmax=0;
		int max=0;
		for(auto it : mymap){
			if(it.second > max){
				max=it.second;
				countmax=1;
			}else if(it.second==max){
				countmax++;
			}
		}
		int total=(max-1)*(interval+1)+countmax;
		return max(nums.size(), total);
	}
	
};