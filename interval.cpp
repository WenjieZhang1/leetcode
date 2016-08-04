#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int intervals(vector<int> &nums, int range){
		int ss=nums.size();
		return ss/range+(ss%range==0 ? 0 : 1);
	}
	
};

int main(){
	Solution ss;
	int range=2;
	vector<int> nums={3,1,3,4,5};
	int res=ss.intervals(nums, range);
	cout<<res<<endl;
	return 0;
}