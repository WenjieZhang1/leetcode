#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
#define random(x) (rand()%x)
using namespace std;
//----- O(logn) ------ O(k) -----//
class Solution
{
public:
	vector<int> Klargest(TreeNode* root, int k){
		vector<int> res;
		if(root==NULL){
			return res;
		}
		stack<TreeNode*> st;
		while(root){
			st.push(root);
			root=root->right;
		}
		while(!st.empty() && res.size()<k){
			TreeNode* cur=st.top();
			st.pop();
			res.push_back(cur->val);
			TreeNode* temp=cur->left;
			while(temp){
				st.push(temp);
				temp=temp->right;
			}
		}
		return res;
	}
	
};