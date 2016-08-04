#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countsort(vector<int> &nums){
		int s=nums.size();
		vector<int> b(s,0);
		int max=nums[0];
		int min=nums[0];
		for(int i=0; i<s; ++i){
			if(nums[i]>max){
				max=nums[i];
			}
			if(nums[i]<min){
				min=nums[i];
			}
		}
		int k=max-min+1;
		cout<<k<<endl;
		vector<int> c(k, 0);
		for(int i=0; i<s; ++i){
			c[nums[i]-min]+=1;
		}
		cout<<"print C"<<endl;
		for(auto it : c){
			cout<<it;
		}
		cout<<'\n';
		int ss=c.size();
		cout<<ss<<endl;
		for(int i=1; i<ss; ++i){
			c[i]=c[i]+c[i-1];
		}
	    cout<<"print C"<<endl;
		for(auto it : c){
			cout<<it;
		}
		cout<<'\n';
		for(int i=s-1; i>=0; --i){
			b[--c[nums[i]-min]]=nums[i];
		}
		return b;


	}
	
};

int main(){
	Solution sl;
	vector<int> nums={1,2,4,3,6,3,2,21,43,21,4};
	vector<int> res;
	res=sl.countsort(nums);
	for(auto it : res){
		cout<<it;
	}
	cout<<endl;
	return 0;
}