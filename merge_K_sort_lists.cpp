# include <iostream>
# include <vector>
using namespace std;
/*int removeDuplicates(vector<int>& nums) {
//       int length=nums.size();
       int res = nums.size();
       int record=nums[0];
       int cur=0;
       while(cur<length){
           cur=cur+1;
           if(nums[cur]==record){
               res-=1;
           }else {
               record=nums[cur];}
       }
       return res;
    }*/
int main(){
	vector<int> nums;
    for(int i=0; i<15; ++i){
    	nums[i]=i;
    }
  //  int x = removeDuplicates(nums);
    cout<<nums[2]<<endl;
    return 0;

}