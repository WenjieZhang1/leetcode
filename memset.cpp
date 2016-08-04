#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;

class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int> &nums) {
    	int n = nums.size();
        sums.resize(n);
        sums[0] = nums[0];
        for(int i=1; i < n; ++i){
            sums[i] = sums[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j] - sums[i];
    }
};

int main()
{
	// vector<vector<int>> sums;
 //    sums.resize(5);
 //    for(int i = 0; i < 5; ++i){
 //        for(int j = 0; j < 5; ++j){
 //            sums[i].push_back(0);
 //        }
 //    }
 //    for(int i=0; i<5; ++i){
 //    	cout<<endl;
 //    	for(int j = 0; j < 5; ++j){
 //    		cout<<sums[i][j];
 //    	}
 //    }
	
	vector<int> nums{-2, 0, 3, -5, 2, -1};
	NumArray nn(nums);
	int res;
	res = nn.sumRange(1, 5);
	cout<<res;
	/* code */
	return 0;
}