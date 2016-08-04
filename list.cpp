#include <list>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class solution{
public:
	// bool alluni(string s){
	// 	int ss=s.length();
	// 	int checker=0;
	// 	for(int i=0; i<ss; ++i){
	// 		int val=s[i]-'a';
	// 		if(checker & 1<<val){
	// 			return false;
	// 		}
	// 		checker |= 1<<val;
	// 	}
	// 	return true;
	// }
	// bool permutation(const string &a, const string &b){
	// 	vector<int> res(128, 0);
	// 	int s1=a.length();
	// 	int s2=b.length();
	// 	if(s1!=s2) return false;
	// 	for(int i=0; i<s1; ++i){
	// 		int val=a[i]-'a';
	// 		res[val]++;
	// 	}

	// 	for(int i=0; i<s2; ++i){
	// 		int val=b[i]-'a';
	// 		res[val]--;
	// 	}

	// 	for(auto it : res){
	// 		if(it!=0){
	// 			return false;
	// 		}
	// 	}
	// 	return true;
	// }
	// void shrink(string &s){
	// 	auto it = s.end();
	// 	it--;
	// 	while(*it==' '){
	// 		s.erase(it);
	// 		it--;
	// 	}
	// 	auto itr=s.begin();
	// 	while(*itr==' '){
	// 		itr++;
	// 	}
	// 	s.erase(s.begin(), itr);
		
	// }

	// string URLift(string s){
	// 	shrink(s);
	// 	vector<string> res;
	// 	int start=0;
	// 	int ss=s.length();
	// 	for(int i=0; i<ss; ++i){
	// 		if(s[i]==' '){
	// 			res.push_back(s.substr(start, i));
	// 			start=i+1;
	// 		}
	// 	}
	// 	string result="";
	// 	for(auto it : res){
	// 		result+=it+"%20";
	// 	}
	// 	return result;
	// }

	int qsort(vector<int>& nums, int k){
		int ss=nums.size();
		int L=0, R=ss-1;
		while(L<R){
			int left=L, right=R;
			int key=nums[left];
			while(left<right){
				while(left<right && nums[right]<key) right--;
				nums[left]=nums[right];
				while(left<right && nums[left]>key) left++; 
			}
			nums[left]=key;
			if(left==k-1) return nums[left];
			else if(left>k-1) R=left-1;
			else L=left+1;
		}
		return nums[k-1];
	}


};

int main(){
	solution SS;
	vector<int> v {1,6,4,5,7,2,8};
	cout<<SS.qsort(v, 5);



	return 0;
}