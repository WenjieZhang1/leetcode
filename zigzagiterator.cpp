#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class zigzagiterator
{
private:
	queue<pair<vector<int> :: iterator, vector<int> :: iterator>> Q;
public:
	zigzagiterator(vector<int> v1, vector<int> v2){
		int s1=v1.size();
		int s2=v2.size();
		if(s1!=0){
			Q.push(make_pair(v1.begin(), v1.end()));
		}
		if(s2!=0){
			Q.push(make_pair(v2.begin(), v2.end()));
		}
	}

	int next() {
		auto it=Q.front().first;
		auto endit=Q.front().second;
		Q.pop();
		if(++it!=endit){
			Q.push(make_pair(it+1, endit));
		}
		return *it;
        
    }

    bool hasNext() {

    	return !Q.empty();
        
    }
	~zigzagiterator();
	
};

int main(){

	vector<int> v1={1,2};
	vector<int> v2={3,4,5,6};
	zigzagiterator zz(v1, v2);
	// zz.zigzagiterator(v1, v2);
	while(zz.hasNext()){
		cout<<zz.next()<<" ";
	}
	cout<<'\n';
	return 0;
}