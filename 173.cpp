//173. Binary Search Tree Iterator
// Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
// 
// Calling next() will return the next smallest number in the BST.
// 
// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
#define NULL 0
#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class BSTIterator {
 public:
	 TreeNode *current;
	 vector<TreeNode*> visited;
	 BSTIterator(TreeNode *root) {
		 current = root;
		 //visited.push_back(NULL);//����[7,4,9,3,5]��©7,9,�����������������
		 while (current!=NULL&&current->left != NULL)//û�д���root�ǿ�ָ�����
		 {
			 visited.push_back(current);
			 current = current->left;
		 }

	 }
	/** @return whether we have a next smallest number */
	bool hasNext() {
		//return !visited.empty();//��ȡ��
		return current != NULL;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = current;
		if (current->right != NULL) {//û�д���current�ǿ�ָ�����,������hasNext()��next()�����������״��
			current = current->right;
			while (current->left != NULL) {
				visited.push_back(current);
				current = current->left;
			}
		}
		else if (!visited.empty()) {
			current = visited.back();
			visited.pop_back();
		}
		else
			current = NULL;
		return node->val;
	}
};
 int main() {

	 BSTIterator bsti(NULL);
	 while (bsti.hasNext())
	 {
		int  a = bsti.next();
	 }
		 
	 return 0;
 }

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/