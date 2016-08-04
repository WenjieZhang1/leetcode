# include <iostream>
# include <stack>
# include <string>
# include <vector> 
using namespace std;
int main(){
	stack<int> ss;
	ss.push(1);
	ss.push(2);
	ss.push(3);
	ss.push(5);
	ss.push(7);
	int i=ss.size();
	cout<<i<<endl;
	ss.pop();
	int x=ss.top();
	cout<<x<<endl;
	string w="wasd";
    string w1=w.substr(1);
	vector<vector<int>> v {{0,1}, {1,0}};
	cout<<w1<<endl;
	if('1'==1+'0') cout<<"wocao"<<endl;
	else cout<<"nima"<<endl;
	return 0;
    
}