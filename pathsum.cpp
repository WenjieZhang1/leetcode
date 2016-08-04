#include <iostream>
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
	vector<vector<int>> path(TreeNode* root, int target){
		vector<vector<int>> res;
		vector<int> temp;
		if(root==NULL) return res;
		int sum=0;
		dfs(res, temp, root, sum, target);
		return res;
	}

	void dfs(vector<vector<int>>& res, vector<int>& temp, TreeNode* root, int &sum, int target){
		if(root==NULL || sum>target){
			return;
		}
		if(root->left==NULL && root->right==NULL){
			if(sum+root->val==target){
				temp.push_back(root->val);
				res.push_back(temp);
				temp.pop_back();
			}
			return; 
		}
		sum+=root->val;
		temp.push_back(root->val);
		dfs(res, temp, root->left, sum, target);
		dfs(res, temp, root->right, sum, target);
		sum-=root->val;
		temp.pop_back();

	}
	
};