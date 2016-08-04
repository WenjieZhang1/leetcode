# include <iostream>
# include <vector>
# include <map>
# include <stack>
# include <cstdlib>
# include <string>
# include <unordered_set>
# include <unordered_map>
# include <queue>

using namespace std;
//struct ListNode {
//         int val;
//         ListNode *next;
//         ListNode(int x) : val(x), next(NULL) {}
//     };

 struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
     };

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    if(intervals.size()==0){
        res.push_back(newInterval);
        return res;
    }
    int flag=0;
    int s=intervals.size();
    Interval temp=intervals[0];
    if(newInterval.end<temp.start){
        res.push_back(newInterval);
    }
    for(int i=0; i<s; ++i){
        if(temp.end<newInterval.start || temp.start>newInterval.end){
            res.push_back(temp);
            temp=intervals[i];
        }else{
            flag=1;
            temp.start=min(temp.start, newInterval.start);
            int j=i;
            while(intervals[j].start<newInterval.end && j<s){
                j++;
            }
            temp.end=max(intervals[j-1].end, newInterval.end);
            res.push_back(temp);
            i=j;
            if(i==s) return res;
            if(i<s){
                temp=intervals[i];
            }
        }
    }
    res.push_back(temp);
    if(flag==0){
        res.push_back(newInterval);
    }
    return res;
}

int main(){
    //vector<vector<char>> matrix;
    //matrix=generate(3);
    vector<int> n1;
    n1.push_back(1);
//    n1.push_back(7);
//    n1.push_back(7);
//    n1.push_back(8);
//    n1.push_back(8);
//    n1.push_back(10);
    //vector<char> n2;
    //n2.push_back('X');
    //n2.push_back('0');
    //n2.push_back('0');
    //n2.push_back('X');
    //vector<char> n3;
    //n3.push_back('X');
    //n3.push_back('X');
    //n3.push_back('0');
    //n3.push_back('X');*/
    /*vector<char> n4;
    n4.push_back('X');
    n4.push_back('0');
    n4.push_back('X');
    n4.push_back('X');*/
    
    //matrix.push_back(n1);
    //matrix.push_back(n2);
    //matrix.push_back(n3);
    //matrix.push_back(n4);
    //n1.push_back(2);
    //n1.push_back(3);
    //matrix=subsetsWithDup(n1);
    //matrix.push_back(n1);
    //n1.push_back(3);
    //n1.push_back(9);
    //n1.push_back(2);
    //n1.push_back(2);
    //n1.push_back(3);
    //int res;
//    vector<int> n2;
//    n2.push_back(1);
//    n2.push_back(4);
    //n2.push_back(6);
    //n2.push_back(7);
    /*vector<int> n3;
    n3.push_back(7);
    n3.push_back(8);
    n3.push_back(9);*/

//    bool res;
    
    //vector<int> nums;
    //int res;
    //res=longestConsecutive(n1);
    //cout<<res;
    //for(auto it=nums.begin(); it!=nums.end(); ++it){
   //     cout<<*it<<endl;
   // }
    //nums.push_back(-1);
    //nums.push_back(1);
    //nums.push_back(2);
    //nums.push_back(4);
    //nums.push_back(0);
    //nums.push_back(4);
//    nums.push_back(1);
    //nums.push_back(5);
    //nums.push_back(7);
//    int k=3;
//    int n=9;
//    vector<vector<int>> res;
//    int res;
    //res= maximalSquare(matrix);
    //cout<<res<<endl;
    //int res;
    //string s="101";
/*    ListNode* l1= new ListNode(3);
    ListNode* l2= new ListNode(5);
    ListNode* l3= new ListNode(8);
    ListNode* l4= new ListNode(9);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    
    //int res;
    TreeNode* root;
    root=sortedListToBST(l1);*/
    /*ListNode* head= new ListNode(1);
    ListNode* h1= new ListNode(2);
    ListNode* h2= new ListNode(3);
    ListNode* h3= new ListNode(4);
    ListNode* h4= new ListNode(5);
    head->next=h1;
    h1->next=h2;
    h2->next=h3;
    h3->next=h4;
    h4->next=nullptr;
    reorderList(head);*/
/*    Point p1 = new Point(1,2);
    Point p2 = new Point(1,2);
    Point p3 = new Point(1,4);
    Point p4 = new Point(2,2);*/
/*    vector<Point> x;
    x.push_back(p1);
    x.push_back(p2);*/
  
    //int s=4;
    //vector<string> res;
   // res= summaryRanges(nums);

    //vector<int> res;
//    string res;
//    vector<string> strs;
//    strs.push_back("abca");
//    strs.push_back("abc");
//    ListNode* H1=new ListNode(1);
//    ListNode* H2=new ListNode(2);
    Interval i1= Interval(1, 5);
    vector<Interval> ss;
    ss.push_back(i1);
    Interval i2= Interval(2,3);
    vector<Interval> res;
    res=insert(ss, i2);
    
    


    return 0;
    
}