#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Cmp{
public:
	 bool operator()(int a, int b){
		return a>b;
	}
};
class Solution
{
public:
	int findkth(vector<int> &nums, int k){
		int ss=nums.size();
		if(ss<k) return -1;
		priority_queue<int, vector<int>, Cmp> pq;
		for(int i=0; i<k; ++i){
			pq.push(nums[i]);
		}
		for(int i=k; i<ss; ++i){
			if(pq.top()<nums[i]){
				pq.pop();
				pq.push(nums[i]);
			}
		}

		return pq.top();


	}
	
};

int main(){
	Solution ss;
	int k=3;
	vector<int> nums={1,2,3,4,2,3};
	int res=ss.findkth(nums, k);
	cout<<res<<'\n';
	return 0;
}