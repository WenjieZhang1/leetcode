#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution{
public:
	vector<int> pre2po(vector<int>& preorder){
		// vector<int> inorder=preorder;
		// sort(inorder.begin(), inorder.end());
		// TreeNode* root=buildtree(preorder, inorder);
		vector<int> res;
		int ss=preorder.size();
		if(ss==0) return res;
		posthelper(preorder, 0, ss-1, res);
		return res;
	}
	void posthelper(vector<int>& preorder, int l, int r, vector<int>& res){
		if(l==r){
			res.push_back(preorder[l]);
			return;
		}
		if(l>r) return;
		int i=l+1;
		for(; i<=r; ++i){
			if(preorder[i]>preorder[l]){
				break;
			}
		}
		posthelper(preorder, l+1, i-1, res);
		posthelper(preorder, i, r, res);
		res.push_back(preorder[l]);
	}

	// TreeNode* buildtree(vector<int>& preorder, vector<int>& inorder){
	// 	int s=inorder.size();
	// 	unordered_map<int, int> mymap;
	// 	for(int i=0; i<s; ++i){
	// 		mymap[inorder[i]]=i;
	// 	}

	// 	return helper(preorder, mymap, 0, 0, s);

	// }

	// TreeNode* helper(vector<int>& preorder, unordered_map<int,int>& mymap, int ps, int offset, int s){
 //        if(s==0) return NULL;
 //        TreeNode* root=new TreeNode(preorder[ps]);
 //        int index=mymap[preorder[ps]];
 //        int l=index-offset;
 //        root->left=helper(preorder, mymap, ps+1, offset, l);
 //        root->right=helper(preorder, mymap, ps+l+1, offset+l+1, s-1-l);
 //        return root;
	// }
};


int main(){
	Solution ss;
	vector<int> preorder;
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(1);
	preorder.push_back(4);
	preorder.push_back(7);
	preorder.push_back(6);
	preorder.push_back(9);
	vector<int> postorder=ss.pre2po(preorder);
	for(auto it : postorder){
		cout<<it<<endl;
	}
	return 0;
}