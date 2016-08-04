#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	vector<string> v={"abs", "qwe", "wer", "qwe"};
	for(auto it : v){
		cout<<it<<" ";
	}
	cout<<'\n';
	reverse(v.begin(), v.end());
	for(auto it : v){
		cout<<it<<" ";
	}
	cout<<'\n';
	return 0;

}