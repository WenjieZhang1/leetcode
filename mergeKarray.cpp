// Naive algorithm for building suffix array of a given text
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    /**
     * @param arrays k sorted integer arrays
     * @return a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
        // Write your code here
        map<int, int> mymap;
        for(auto it : arrays){
        	int s=it.size();
            for(int i=0; i<s; ++i){
                mymap[it[i]]++;
            }
        }
        vector<int> res;
        for(auto it : mymap){
            while(it.second!=0){
                res.push_back(it.first);
                it.second--;
            }
        }
        return res;
    }
};
int main(){
	Solution ss;
	vector<vector<int>> arrays;
	vector<int> n1={1, 3, 5, 7};
	vector<int> n2={2, 4, 5, 6};
	vector<int> n3={0, 8, 9, 10, 11};
	arrays.push_back(n1);
	arrays.push_back(n2);
	arrays.push_back(n3);
	vector<int> res;
	res=ss.mergekSortedArrays(arrays);
	for(auto it : res){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;


}