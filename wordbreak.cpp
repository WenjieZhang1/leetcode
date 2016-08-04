#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool wordbreak(string word, unordered_map<int> dic){
		int ss=word.length();
		vector<bool> res(ss+1, false);
		res[0]=true;
		for(int i=1; i<=ss; ++i){
			for(int j=i-1; j>=0; --j){
				if(res[j] && dic.find(word.substr(j, i-j))!=dic.end()){
					res[i]=true;
					break;
				}
			}
		}
		return res[ss];
	}
	
};