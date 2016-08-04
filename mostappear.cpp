#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
	int mostappear(vector<int>& nums){
		// unordered_map<int, int> mymap;
		// int ss=nums.size();
		// for(int i=0; i<ss; ++i){
		// 	mymap[nums[i]]++;
		// }
		// int max=0;
		// int res;
		// for(auto it : mymap){
		// 	if(it.second > max){
		// 		res=it.first;
		// 		max=it.second;
		// 	}
		// }
		// return res;
		sort(nums.begin(), nums.end());
		int max=0;
		int res;
		int ss=nums.size();
		for(int i=0; i<ss; ++i){
			int count=1;
			while(i<ss-1 && nums[i]==nums[i+1]){
				count++;
				i++;
			}
			res = max > count ? res : nums[i];
			max = (max > count) ? max : count;

		}
		cout<<max<<endl;
		return res;
	}
	
};

int main()
{
	Solution ss;
	vector<int> nums = {1,2,4,5,1,2,1,4,1,6,1};
	int res=ss.mostappear(nums);
	cout<<res<<endl;
	return 0;
}