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
	int findksmallest(TreeNode* root, int k){
		int count=nodenumber(root->left)+1;
		if(k==count) return root->val;
		if(k<count) return findksmallest(root->left, k);
		if(k>count) return findksmallest(root->right, k-count);
	}

	int nodenumber(TreeNode *root){
		if(root==NULL) return 0;
		return 1+nodenumber(root->left)+nodenumber(root->right);
	}
	
};
