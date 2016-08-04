#include <iostream>
#include <queue>
#include <vector>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root){
		vector<vector<int>> res;
		if(root==NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		int level=1;
		while(!q.empty()){
			int ss=q.size();
			vector<int> temp;
			for(int i=0; i<ss; ++i){
				TreeNode* temp=q.front();
				q.pop();
				temp.push_back(temp->val);
				if(temp->left){
					q.push(temp->left);
				}
				if(temp->right){
				q.push(temp->right);
			    }
			}
			if(level%2){
				reverse(temp.begin(), temp.end());
				res.push_back(temp);
			}else{
				res.push_back(temp);
			}
			level++;
		}
		return res;
	}
};