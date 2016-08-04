#include<iostream>  
#include<vector>  
#include<algorithm>  

using namespace std;

int main(){
	vector<int> num;
    num.push_back(10);
    num.push_back(11);
    num.push_back(3);
    num.push_back(34);
	num.push_back(10);
    num.push_back(-1);
	sort(num.begin(), num.end());
	copy (num.begin(), num.end(), ostream_iterator<int> (cout, "\n")); 
	return 0;

}
