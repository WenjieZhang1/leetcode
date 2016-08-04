# include <iostream>
# include <vector>
# include <string>
using namespace std;
int main(){
	vector<int> qs;
    qs.push_back(2);
	qs.push_back(5);
	qs.push_back(4);
	qs.push_back(7);
	qs.push_back(2);
	qs.push_back(9);
	reverse(qs.begin(), qs.end());
	for(auto it=qs.begin(); it!=qs.end(); it++){
		cout<<*it;
	}
 
    return 0;


}