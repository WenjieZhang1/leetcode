# include <iostream>
# include <vector>
using namespace std;
int binarysearch(vector<int> &nums, int begin, int end, int target){
    int mid=(begin+end)/2;
    cout<<'*'<<endl;
    while(begin<end){
        if(target<nums[mid]){
            end=mid-1;
            mid=(begin+end)/2;
        }else if(target>nums[mid]){
            begin=mid+1;
            mid=(begin+end)/2;
        }else
            return mid;
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int res;
        int point=-1;
        int s=nums.size();
//      int res;
        for(int i=s-1; i>=0; i--){
            if(nums[i]<nums[i-1]){
                point=i;
                break;
            }
        }

        
        if(target<nums[s-1]){
           res=binarysearch(nums, point+1, s-1, target); 
           return res;
       }else if(target>nums[s-1]){
           res=binarysearch(nums, 0, point-1, target);
           return res;
        }else return point;
    }


int main(){
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    int x=search(nums,4);
    cout<<x<<endl;
    return 0;

}