#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	void insertionsort(vector<int> &nums){
		int ss=nums.size();
		for(int i=1; i<ss; ++i){
			int j=i-1;
			int key=nums[i];
			while(j>=0 && key<nums[j]){
				nums[j+1]=nums[j];
				j--;
			}
			nums[j+1]=key;
		}
	}
	
};

int main(){
	vector<int> nums={1,4,2,5,3,7,6,9};
	Solution ss;
	ss.insertionsort(nums);
	for(auto it : nums){
		cout<<it<<" ";
	}
	string sss="abs";


	cout<<sss.substr(0,1)<<endl;

	cout<<sss<<'\n';
	cout<<endl;
	return 0;
}