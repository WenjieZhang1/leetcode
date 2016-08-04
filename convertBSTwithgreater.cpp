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
	void add(TreeNode *root){
		int sum=0;
		addgreater(root, &sum);
	}

	void addgreater(TreeNode *root, int *sum){
		if(root==NULL) return ;

		addgreater(root->right, sum);

		*sum=*sum+root->val;

		root->val=*sum;

		addgreater(root->left, sum);

	}

	void printtree(TreeNode *root){
		if(root==NULL) return;
		printtree(root->left);
		cout<<root->val;
		printtree(root->right);
	}
	
};

int main(){
	Solution ss;
	TreeNode *root =new TreeNode(5);
	root->left=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->right=new TreeNode(13);
	ss.printtree(root);
	ss.add(root);
	cout<<'\n';
	ss.printtree(root);
	return 0;
}