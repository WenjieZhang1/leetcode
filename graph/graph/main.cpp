//
//  main.cpp
//  graph
//
//  Created by Wenjie Zhang on 2/1/16.
//  Copyright © 2016 Wenjie Zhang. All rights reserved.
//

#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;

vector<int> countnums(vector<int> nums){
    int s=nums.size();
    vector<int> res(s);
    int capital=0;
    for(int i=0; i<s; ++i){
        if(nums[i]==i){
            capital=i;
            break;
        }
    }
    unordered_map<int,int> mymap;
    for(int i=0; i<s; ++i){
        int next=i;
        int dis=0;
        while(next!=capital){
            next=nums[next];
            dis++;
            if(mymap.find(next)!=mymap.end()){
                dis+=mymap[next];
                break;
            }
        }
        mymap[i]=dis;
        res[dis]++;
    }
    res.erase(res.begin());
    return res;
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    vector<int> res;
    res=countnums(nums);
    for(auto it=res.begin(); it!=res.end(); ++it){
        cout<<*it;
    }
    
    return 0;
}
