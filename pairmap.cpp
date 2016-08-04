#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Compare {
public:
    bool operator() (const pair<int, int> p1, const pair<int, int> p2) const {
        return (p1.first + p1.second) > (p2.first + p2.second);
    }
};
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
        vector<pair<int,int>> res;
        int s1 = nums1.size();
        int s2 = nums2.size();
        for(int i = 0; i < s1; ++i){
            for(int j = 0; j < s2; ++j){
                q.push(make_pair(nums1[i], nums2[j]));
            }
        }
        int i = 0;
        int qsize = q.size();
        while(i < k && i < qsize){
            res.push_back(q.top());
            i++;
            q.pop();
        }
        return res;
    }
};
int main(){
	vector<int> nums1 {1,7,11};
	vector<int> nums2 {2,4,6};
    // sort(nums2.rbegin(), nums2.rend());
    // for(int i=0; i<3; ++i){
    //     cout<<nums2[i];
    // }
	Solution ss;
	vector<pair<int,int>> res;
	res = ss.kSmallestPairs(nums1, nums2, 10);
	int si = res.size();
	for(int i = 0; i<si; ++i){
        cout<<"(" << res[i].first <<"," << res[i].second <<")" <<'\n';
    }
	return 0;
}