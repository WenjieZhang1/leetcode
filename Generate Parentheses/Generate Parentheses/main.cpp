//
//  main.cpp
//  Generate Parentheses
//
//  Created by Wenjie Zhang on 12/13/15.
//  Copyright © 2015 Wenjie Zhang. All rights reserved.
//

#include <iostream>
# include <vector>
using namespace std;


void generateParenthesis(int left, int right, string s, vector<string> &res){
    if(left==0 && right==0){
        res.push_back(s);
    }
    if(left>0){
        generateParenthesis(left-1, right, s+'(', res);
    }
    if(right>0 && left<right){
        generateParenthesis(left, right-1, s+')', res);
    }
}
int main(){
    int n=3;
    vector<string> res;
    generateParenthesis(n, n, "", res);
    
    for(int i=0; i<5; ++i){
        cout<<res[i]<<'\n';
    }
    
    return 0;
    
}
