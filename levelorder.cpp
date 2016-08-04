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
	vector<int> levelorder(TreeNode* root){
		queue<int> qe;
		vector<vector<int>> res;
		if(root==NULL) return res;
		TreeNode* p=root;
		qu.push(p);
		while(!qe.empty()){
			int ss=qe.size();
			vector<int> temp;
			for(int i=0; i<ss; ++i){
				p=qe.front();
				qe.pop();
				temp.push_back(p->val);
				if(p->left){
					qe.push(p->left);
				}
				if(p->right){
					qe.push(p->right);
				}
			}
			res.push_back(temp);
		}
		return res;
	}
	
};