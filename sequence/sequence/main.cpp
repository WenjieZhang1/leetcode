#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int start = 0;
        int end = citations.size()-1;
        int len = citations.size();
        while(start+1 < end){
            int mid = start+(end-start)/2;
            if(citations[mid]==len-mid) return len-mid;
            else if(citations[mid] < len-mid) start=mid;
            else end=mid;
        }
        return len-end;
    }
    
};


int main(){
    vector<int> citations={1,2,3,4,5,6};
    Solution ss;
    int res;
    res=ss.hIndex(citations);
    cout<<res<<endl;
    
    return 0;
}