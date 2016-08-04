#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
	int count1(int input){
		int count=0;
		for(int i=0; i<32; ++i){
			if((input & 1)!=0){
				count++;
			}
			input>>=1;
		}
		return count;
	}
	
};

int main(){
	Solution ss;

	int intput=10;

	cout<<ss.count1(intput);

	return 0;
}