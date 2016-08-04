#include <iostream>
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
	bool issys(TreeNode* root){
		if(root==NULL) return true;
		return helper(root->left, root->right);
	}

	bool helpe(TreeNode* rootl, TreeNode* rootr){
		if(rootl==NULL && rootr==NULL) return true;
		if(rootl==NULL || rootr==NULL) return false;
		if(rootr->val!=rootl->val) return false;
		return (helper(rootl->left, rootr->right) && (rootl->right, rootr->left));
	}
	
};