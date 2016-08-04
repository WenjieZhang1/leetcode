#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#define random(x) (rand()%x)
using namespace std;

class Solution
{
public:
	vector<int> avergeK(vector<int> &nums, int k){
		vector<int> res;
		int s=nums.size();
		if(s<k){
			return res;
		}
		int count=0; 
		int i=0;
		int sum=0;
		for(; i<s; ++i){
			sum+=nums[i];
			count++;
			if(count==k){
				res.push_back(sum/k);
				sum-=nums[i-k+1];
				count--;
			}
		}
		return res;
	}
	
};

int main(){
	Solution ss;
	int k=3;
	vector<int> nums={1,3,5,7,9};
	std::vector<int> res;
	res=ss.avergeK(nums, k);
	for(auto it : res){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}