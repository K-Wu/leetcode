//98. Validate Binary Search Tree
#define NULL 0
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
// bool isVaildNode(TreeNode* node,TreeNode* father) {
// 	if (node == father || (node == father->left&&node->val < father->val) || (node == father->right&&node->val > father->val)) {
// 		if (node->left == NULL || (node->left-> val< node->val)) {
// 			if (node->right == NULL || (node->right->val > node->val)) {
// 				return true;
// 			}
// 			else
// 				return false;
// 		}
// 		else return false;
// 	}
// 	else return false;
// 
// 	
// }

void recoverTree(TreeNode* root, TreeNode* fathernode, vector<pair<TreeNode*, TreeNode*> >& invalid_nodes) {
	if ((root == fathernode->left&&root->val >= fathernode->val) || (root == fathernode->right&&root->val <= fathernode->val)) {
		invalid_nodes.push_back(make_pair(root,fathernode));
	}
	if (root->left != NULL)
		recoverTree(root->left, root, invalid_nodes);//@param fathernode Ð´³Éfathernode
	if (root->right != NULL)
		recoverTree(root->right, root, invalid_nodes);
	

}
void recoverTree(TreeNode* root) {
	vector<pair<TreeNode*, TreeNode*> > invalid_nodes;//node,fathernode
	recoverTree(root, root, invalid_nodes);
	if (invalid_nodes.size() == 1) {
		int first_val = invalid_nodes.at(0).first->val;
		invalid_nodes.at(0).first->val = invalid_nodes.at(0).second->val;
		invalid_nodes.at(0).second->val = first_val;//µÈºÅÓÒ±ßÐ´³Éinvalid_nodes.at(0).first->val
	}
	else if (invalid_nodes.size() == 2 && ((invalid_nodes.at(0).first == invalid_nodes.at(1).second) || (invalid_nodes.at(0).second == invalid_nodes.at(0).first)))
	{
		int first_val = invalid_nodes.at(0).first->val;
		invalid_nodes.at(0).first->val = invalid_nodes.at(0).second->val;
		invalid_nodes.at(0).second->val = first_val;//µÈºÅÓÒ±ßÐ´³Éinvalid_nodes.at(0).first->val
	}
	else {
		int zero_val = invalid_nodes.at(0).first->val;
		invalid_nodes.at(0).first->val = invalid_nodes.at(1).first->val;
		invalid_nodes.at(1).first->val = zero_val;//µÈºÅÓÒ±ßÐ´³Éinvalid_nodes.at(0).first->val
	}
}
int main() {

	TreeNode* root = new TreeNode(0);
	TreeNode* leaf = new TreeNode(1);
	root->left = leaf;	
	recoverTree(root);
	return 0;
}