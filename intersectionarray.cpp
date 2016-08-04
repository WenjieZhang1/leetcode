// Naive algorithm for building suffix array of a given text
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
	vector<int> intersection(vector<int>& A1, vector<int>& A2){
		set<int> myset1;
		vector<int> res;
		int l1=A1.size();
		for(int i=0; i<l1; ++i){
			myset1.insert(A1[i]);
		}
		int l2=A2.size();
		for(int i=0; i<l2; ++i){
			if(myset1.find(A2[i])!=myset1.end()){
				res.push_back(A2[i]);
			}
		}
		return res;
	}
	//------has duplicate--------//
	vector<int> intersection2(vector<int>& A1, vector<int>& A2){
		unordered_map<int, int> mymap;
		int len1=A1.size();
		for(int i=0; i<len1; i++){
			mymap[A1[i]]++;
		}
		int len2=A2.size();
		vector<int> res;
		for(int i=0; i<len2; ++i){
			if(mymap.find(A2[i])!=mymap.end()){
				res.push_back(A2[i]);
				mymap[A2[i]]--;
			}
		}
		return res;
	}
};


int main(){
	Solution ss;
	vector<int> res;
	vector<int> A1={1,2,3,4,5,5};
	vector<int> A2={1,2,4,5,6,5};
	res=ss.intersection2(A1, A2);
	for(auto it : res){
		cout<<it<<" ";

	}
	cout<<'\n';
	return 0;
}