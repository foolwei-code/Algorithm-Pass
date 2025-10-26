#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
//前置 :二叉树的建立
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
		if (root == nullptr)
			return ans;
		stack<TreeNode*>stack;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode* top = stack.top();
			stack.pop();
			ans.push_back(top->val);
			if (top->right != nullptr)
				stack.push(top->right);
			if (top->left != nullptr)
				stack.push(top->left);
		}
		return  ans;
	}
};
//2.中序遍历
//测试链接:https://leetcode.cn/problems/binary-tree-inorder-traversal/
class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>ans;
		if (root == nullptr)
			return ans;
		stack<TreeNode*>stack;
		unordered_set<TreeNode*>set;
		stack.push(root);
		while (!stack.empty())
		{
			//将左孩子入栈
			TreeNode* top = stack.top();
			if (top->left != nullptr && !set.count(top->left))
			{
				stack.push(top->left);
				set.insert(top->left);
			}
			else
			{
				stack.pop();
				ans.push_back(top->val);
				if (top->right != nullptr)
					stack.push(top->right);
			}
		}
		return  ans;
	}
};

//3.后序遍历
//测试链接:https://leetcode.cn/problems/binary-tree-postorder-traversal/
//使用两个栈的方法
class Solution3 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		//先按照根右左的方式进行遍历，将结果存储到栈中，最后将结果压
		//到另一个栈中，即得到左右根
		vector<int>ans;
		if (root == nullptr)
			return ans;
		stack<TreeNode*>stack1;
		stack<int>stack2;
		stack1.push(root);
		while (!stack1.empty())
		{
			TreeNode* top = stack1.top();
			stack1.pop();
			stack2.push(top->val);
			if (top->left != nullptr)
				stack1.push(top->left);
			if (top->right != nullptr)
				stack1.push(top->right);
		}
		//将元素倒入ans中
		while (!stack2.empty())
		{
			ans.push_back(stack2.top());
			stack2.pop();
		}
		return  ans;
	}
};
//用一个栈实现的后序遍历
class Solution4 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>ans;
		if (root == nullptr)
			return ans;
		TreeNode* h = root;
		stack<TreeNode*>stack;
		stack.push(h);
		while (!stack.empty())
		{
			TreeNode* top = stack.top();
			if (top->left != nullptr && h != top->left && h != top->right)
				stack.push(top->left);
			else if (top->right != nullptr && top->right != h)
				stack.push(top->right);
			else
			{
				stack.pop();
				ans.push_back(top->val);
				h = top;
			}
		}
		return  ans;
	}
};
int main()
{
	return  0;
}