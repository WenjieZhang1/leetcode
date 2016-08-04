//
//  main.cpp
//  Frogjump
//
//  Created by Wenjie Zhang on 1/30/16.
//  Copyright © 2016 Wenjie Zhang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int frogjump(vector<int> &A, int X, int D){
        if(D>=X) return 0;
        unordered_map<int,int> mymap;
        int s=A.size();
        mymap[0]=0;
        mymap[X]=0;
        for(int i=0; i<s; ++i){
            if(mymap.find(A[i])==mymap.end()){
                mymap[A[i]]=i;
            }
        }
    
        vector<int> res(X+1,INT_MAX);
        for(int pos=1; pos<=X; ++pos){
            if(mymap.find(pos)!=mymap.end()){
                if(pos<=D){
                    res[pos]=mymap[pos];
                }else{
                    for(int i=1; i<=D; ++i){
                        if(mymap[pos]<res[pos-i]){
                            res[pos]=min(res[pos], res[pos-i]);
                        }else{
                            res[pos]=min(res[pos], mymap[pos]);
                        }
                    }
                }
            }
        }
    return res[X]==INT_MAX ? -1 : res[X];
}



int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(1);
    A.push_back(4);
    A.push_back(2);
    A.push_back(5);
    int res;
    res= frogjump(A, 7, 3);
    cout<<res<<endl;
    return 0;
}
    

