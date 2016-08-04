#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        int s = nums.size();
        if(s == 0){
            return res;
        }
        vector<int> len(s, 1);
        vector<int> path;
        for(int i = 0; i < s; ++i){
            path.push_back(i);
        }
        sort(nums.rbegin(), nums.rend());
        int max_len = 1;
        int start = 0;
        for(int i = 1; i < s; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] % nums[i] == 0){
                    if(len[i] < len[j] + 1){
                        len[i] = len[j] + 1;
                        path[i] = j;
                        if(len[i] > max_len){
                            max_len = len[i];
                            start = i;
                        }
                    }
                }
            }
        }
        while(path[start] != start){
            res.push_back(nums[start]);
            start = path[start];
        }
        res.push_back(nums[start]);
        return res;
    }
};
int main(){
    Solution ss;
    //    vector<vector<int>> nums {{4,16},{15,5},{18,17},{10,12}};
//    string s = "the sky is blue";
//    int res = ss.hammingWeight(2);
//    vector<pair> nums{{};
    vector<int> nums{1, 2, 3};
   vector<int> res = ss.largestDivisibleSubset(nums);

    return 0;
}
