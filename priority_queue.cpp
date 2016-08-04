#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define random(x) (rand()%x)

 /*void main()
{
     for(int x=0;x<10;x++)
           printf("%d/n",random(100));
}*/
using namespace std;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}
/*static bool Compare(const int a, const int b){
	return a>b;
}*/




int fac(int x){
	int res=1;
	int num=x;
	while(num>0){
		res=res*num;
		num--;
	}
	return res;
}
int main(){
	std::priority_queue<int> q;
	for(int n : {1,2,3,4,5,8,7,9,11,10}){
		q.push(n);
	}
	string s="12345";
    s.pop_back();
    s=s.substr(0,2);
	cout<<s<<endl;
	string w="";
	w.insert(0,1,'(');
		cout<<w<<endl;
	int x='A'-64;
	cout<<x<<endl;
	int qv=fac(15);
	cout<<qv<<endl;
	string v;

	v=to_string(10);
	cout<<v<<endl;
	int i=1;
	cout<<(i<<4)<<endl;
	for(int j=0; j<5; ++j){
		cout<<random(69)<<" ";
	}
	cout<<"are fisrt five"<<endl;
	cout<<"last one: "<<random(29)<<endl;
	cout<<(0xffffffff << 0)<<endl;
	vector<int> n1;
	n1.push_back(1);
	n1.push_back(3);
	n1.push_back(2);
	n1.push_back(5);
	n1.push_back(1);
	sort(n1.begin(), n1.end());
	for(auto it=n1.begin(); it!=n1.end(); ++it){
		cout<<*it;
	}
	cout<<endl;

	string h="a s d";
	int ss=h.size();
	string temp=h.substr(0,1);
	//cout<<temp<<endl;
	vector<string> str1;
    int pre=0;
    for(int i=0; i<ss; ++i){
            if(h[i]==' '){
                string temp=h.substr(pre, i);
                str1.push_back(temp);
                pre=i+1;
            }
        }
    for(auto it=str1.begin(); it!=str1.end(); ++it){
    	cout<<*it<<endl;
    }

	

    return 0;
}