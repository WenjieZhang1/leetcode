// Naive algorithm for building suffix array of a given text
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
class compare{
public:
	bool operator()(point a, point b){
		return (b.x*b.x+b.y*b.y)-(a.x*a.x+a.y*a.y)>0;
	}
};

class Solution
{
public:
	vector<point> closetpoints(vector<point> points){
		vector<point> res;
		priority_queue<piont, vector<point>, compare> pq;
		for(int i=0; i<points.size(); ++i){
			if(i<k){
				pq.push(points[i]);
			}else{
				point temp=pq.top();
				if((points[i].x*points[i].x+points[i].y+points[i].y)-(temp.x*temp.x+temp.y*temp.y)>0){
					pq.pop();
					pq.push(nums[i]);
				}
			}
		}
		while(!pq.empty()){
			res.push_back(pq.top());
			pq.pop();
		}
		return res;
	}

	
};