#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
	unordered_map<string, int> mymap = {
     {"mom",5.4},
     {"dad",6.1},
     {"bro",5.9} };
	auto it = mymap.find("mom");
	if(it != mymap.end()){
		cout << "found" <<'\n';
		cout << it->first <<"is" << it->second;
	}
	return 0;
}