#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
//ǰ�� :�������Ľ���
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
//1.�������
//��������:https://leetcode.cn/problems/binary-tree-preorder-traversal/
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
//2.�������
//��������:https://leetcode.cn/problems/binary-tree-inorder-traversal/
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
			//��������ջ
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

//3.�������
//��������:https://leetcode.cn/problems/binary-tree-postorder-traversal/
//ʹ������ջ�ķ���
class Solution3 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		//�Ȱ��ո�����ķ�ʽ���б�����������洢��ջ�У���󽫽��ѹ
		//����һ��ջ�У����õ����Ҹ�
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
		//��Ԫ�ص���ans��
		while (!stack2.empty())
		{
			ans.push_back(stack2.top());
			stack2.pop();
		}
		return  ans;
	}
};
//��һ��ջʵ�ֵĺ������
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