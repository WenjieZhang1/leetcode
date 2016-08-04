#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // vector<int> res;
        // int start = 0;
        // int max_len = 1;
        // if(nums.size() == 0) {
        //     return res;
        // }
        // sort(nums.rbegin(), nums.rend());
        // vector<int> len(nums.size(), 1);
        // vector<int> path(nums.size(), 0);
        // for(int i = 0; i < nums.size(); ++i){
        //     path[i] = i;
        // }
        // for(int i = 1; i < nums.size(); ++i){
        //     for(int j = 0; j < i; ++j){
        //         if(nums[j] % nums[i] == 0){
        //             if(len[i] < len[j] + 1){
        //                 len[i] = len[j] + 1;
        //                 path[i] = j;
        //                 if(len[i] > max_len){
        //                     max_len = len[i];
        //                     start = i;
        //                 }
        //             }
        //         }
        //     }
        // }
        // while(path[start] != start){
        //     res.push_back(nums[start]);
        //     start = path[start];
        // }
        // res.push_back(nums[start]);
        // return res;
        bool flag = false;
        int start = 0;
        int n = nums.size();
        unordered_map<int, vector<int>> mymap;
        for(int i = 0; i < n; ++i){
            for(auto it : mymap){
                cout << it.second.back();
                int ss = it.second.back();
                if(nums[i] % ss == 0){
                    it.second.push_back(nums[i]);
                    cout << it.second.back();
                    flag = true;
                }
            }
            if(!flag){
                mymap[start++] = vector<int>{nums[i]};
                flag = false;
            }
        }
        int max_len = 0;
        int location = 0;
        for(auto it : mymap){
            int s = it.second.size();
            if(s > max_len){
                max_len = it.second.size();
                location = it.first;
            }
        }
        return mymap[location];
    }
};
int main(){
    Solution ss;
    vector<int> res;
    vector<int> nums{1,2,3};
    res = ss.largestDivisibleSubset(nums);
    for(auto it : res){
        cout << it;
    }
    int a = 5;
    int b = 2;
    double c = double(a)/b;
    cout<<'\n' << c <<endl;
    return 0;
}
