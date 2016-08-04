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

class BSTiterator
{
private:
	int nextmin;
	stack<TreeNode*> st;
public:
	
	BSTiterator(TreeNode* root){
		while(root){
			stack.push(root);
			root=root->left;
		}
	}

	bool hasnext(){
		if(!st.empty()){
			TreeNode* top=st.top();
			st.pop();
			nextmin=top->val;
			TreeNode* cur=top->right();
			if(cur){
				st.push(cur);
				cur=cur->left;
				while(cur){
					st.push(cur);
					cur=cur->left;
				}
			}
			return true;
		}
		return false;
	}

	int next(){
		return nextmin;
	}
};
 