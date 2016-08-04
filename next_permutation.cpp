# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
void reverse( vector<int>& nums, int begin, int end){
        int l=begin;
        int r=end;
        while(l<r){
            int temp=nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            l++;
            r--;
        }
    }
using namespace std;
int main(){
   vector<int> V;

   for(int i=0; i<10; ++i){
   	V.push_back(i);
   }
   int s=V.size();
   reverse(V, 0, s-1);
   for(int i=0; i<s; ++i){
   	cout<<V[i]<<endl;

   }
   return 0;


}