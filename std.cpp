# include <iostream>
# include <vector>
using namespace std;
 bool cmp(const int &a, const int &b){
	return a>b;
}
int main(){
	vector<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	d.push_back(6);
	d.push_back(7);
	d.insert(d.begin(),1);
	int m=d.back();
	cout<<m<<endl;
	//d.insert(d.begin()+1,2);
	//sort(d.begin(), d.end(), cmp);

	for(auto it=d.begin(); it!=d.end(); ++it){
		cout<<*it<<endl;
	}
    reverse(d.begin(), d.begin()+7-2);
    reverse(d.begin()+5, d.end());
    reverse(d.begin(), d.end());
	auto itr=d.begin();
	while(itr!=d.end()){
		cout<<*itr++<<endl;
	}
	return 0;
}