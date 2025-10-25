#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//前置：二叉树的建立
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};
//1.先序遍历
//测试链接:https://leetcode.cn/problems/binary-tree-preorder-traversal/
class Solution1 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>ans;
		f(root, ans);
		return ans;
	}
	void f(TreeNode* root, vector<int>& ans)
	{
		if (root == nullptr)
			return;
		ans.push_back(root->val);
		f(root->left, ans);
		f(root->right, ans);
	}
};

//2.中序遍历
//测试链接:https://leetcode.cn/problems/binary-tree-inorder-traversal/
class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>ans;
		f(root, ans);
		return ans;
	}
	void f(TreeNode* root, vector<int>& ans)
	{
		if (root == nullptr)
			return;
		f(root->left, ans);
		ans.push_back(root->val);
		f(root->right,ans);
	}
};

//3.后序遍历
//测试链接:https://leetcode.cn/problems/binary-tree-postorder-traversal/
class Solution3 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>ans;
		f(root, ans);
		return ans;
	}
	void f(TreeNode* root, vector<int>& ans)
	{
		if (root == nullptr)
			return;
		f(root->left, ans);
		f(root->right, ans);
		ans.push_back(root->val);
	}
};

//补充：二叉树的层序遍历
//测试链接:https://leetcode.cn/problems/binary-tree-level-order-traversal/
class Solution4 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>ans;
		if (root == nullptr)
			return ans;
		queue<TreeNode*>queue;
		int size = 0,cnt=0;
		queue.push(root);
		size++;
		while (!queue.empty())
		{
			cnt = 0;
			vector<int>temp;
			for (int i = 0; i < size; i++)
			{
				TreeNode* front = queue.front();
				queue.pop();
				temp.push_back(front->val);
				if (front->left != nullptr)
				{
					queue.push(front->left);
					cnt++;
				}
				if (front->right != nullptr)
				{
					queue.push(front->right);
					cnt++;
				}
			}
			size = cnt;
			ans.push_back(temp);
		}
		return ans;
	}
};
int main()
{
	return 0;
}