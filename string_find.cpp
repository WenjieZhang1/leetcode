#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
// static bool Compare(int a, int b){
// 	return a < b;
// }
int main(){
	// string x1 = "aabs gfbbb";
	// int x3 = x1.find("gfbbb", 4);
	// string x2 = x1.substr(0, x3);
	// string x4 = x1.substr(x3 + 1, 2);
	// string x5 = x1.substr(5);
	// cout<<x3<<endl;
	// cout << x3;
	vector<vector<int>> nums;
	nums.push_back(vector<int>(2, 1));
	nums.insert(nums.begin(), vector<int>(2,1));
	int x = nums.size();
	cout<< x;

	return 0;
}