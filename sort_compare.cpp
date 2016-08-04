#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
class Compare{
public:
    bool operator()(const pair<int,int> p1, const pair<int,int> p2) const{
        return p1.first > p2.first;
    }
};
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), Compare);
        int begin = 0;
        int end = points.size()-1;
        int mid = points[begin++].first + points[end--].first;  
        while(begin <= end){
            if(points[begin++].first + points[end--].first != mid){
                return false;
            }
        }
        return true;
    }
};
int main()
{
	
	/* code */
	return 0;
}