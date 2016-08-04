#include <iostream>
#include <stack>
using namespace std;
using namespace std;
class Solution
{
public:
	bool duplicate(vector<int> &nums, int target){
		unordered_map<int, int> mymap;
		int ss=nums.size();
		for(int i=0; i<ss; ++i){
			if(mymap.find(nums[i])!=mymap.end()){
				if(abs(i-mymap[nums[i]])<=target){
					return true;
				}else{
					mymap[nums[i]]=i;
				}
			}else{
				mymap[nums[i]]=i;
			}
		}
		return false;
	}
	
};

int main(){
	Solution ss;
	bool res;
	vector<int> nums={1,2,3,4,5,6,5};
	int target=2;
	res=ss.duplicate(nums, target);
	cout<<res<<endl;
	return 0;

}