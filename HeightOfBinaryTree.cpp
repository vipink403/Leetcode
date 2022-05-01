#include <iostream>
#include <algorithm>
using namespace std;

/*** Definition for a binary tree node.***/
class TreeNode 
{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

	static int getHeight(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		int left_height = getHeight(root->left);
		int right_height = getHeight(root->right);

		return max(left_height, right_height) + 1;
	}

	static void inorder(const TreeNode* root)
	{
		if (root == nullptr)
			return;

		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
};


int main_Btree()
{
	TreeNode *root = new TreeNode(13);
	root->left = new TreeNode(11);
	root->right = new TreeNode(14);
	root->left->left = new TreeNode(10);
	root->left->right = new TreeNode(12);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(16);
	root->right->left->left = new TreeNode(9);

	//TreeNode::inorder(root);
	cout << TreeNode::getHeight(root) << endl;

	return 0;
}