#include <iostream>
#include <queue>
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
	vector<vector<int>> levelbot(TreeNode* root){
		int height = level(root);
		vector<vector<int>> res(height, vector<int>);
		if(root==NULL) return res;
		queue<int> q;
		q.push(root);
		while(!q.empty()){
			int s=q.size();
			vector<int> temp;
			for(int i=0; i<s; ++i){
				TreeNode *p=q.front();
				q.pop();
				temp.push_back(p->val);
				if(p->left){
					q.push(p->left);
				}
				if(p->right){
					q.push(p->right);
				}
			}
			res[height-1].push_back(temp);

		}
 	}

	int level(TreeNode* root){
		if(root==NULL) return 0;
		return max(level(root->left), level(root->right))+1;
	}
	
};