#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> inorder(TreeNode* root){
		vector<int> res;
		if(root==NULL) return res;
		stack<TreeNode*> st;
		TreeNode* p=root;
		while(!p==NULL || !st.empty()){
			while(p){
				st.push(p);
				p=p->left;
			}
			if(!st.empty()){
				p=st.top();
				st.pop();
				res.push_back(p->val);
				p=p->right;
			}
		}
		return res;

} 
	
};