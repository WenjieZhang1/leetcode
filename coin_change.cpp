#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int minstep(vector<int> &coins, int amount){
		int MAX=amount+1;
		int ss=coins.size();
		vector<int> mins(amount+1, MAX);
		mins[0]=0;
		for(int i=1; i<=amount; ++i){
			for(int j=0; j<ss; ++j){
				if(coins[j]<=i){
					mins[i]=min(mins[i], mins[i-coins[j]]+1);
				}
			}
		}
		return mins[amount]==MAX ? -1 : mins[amount];
	}
	
};

int main(){
	Solution ss;
	vector<int> coins={1,2,5};
	int amount=11;
	int res=ss.minstep(coins, amount);
	cout<<res<<endl;
	return 0;
}