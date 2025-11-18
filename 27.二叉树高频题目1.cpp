#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 1.二叉树的层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-level-order-traversal/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};
class Solution1 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>ans;
		if (root == nullptr)
			return ans;
		vector<TreeNode*>queue(2000);
		int l = 0, r = 0;
		queue[r++] = root;
		while (l < r)
		{
			int size = r - l;
			vector<int>temp;
			for (int i = 0; i < size; i++)
			{
				TreeNode* front = queue[l++];
				temp.push_back(front->val);
				if (front->left != nullptr)
					queue[r++] = front->left;
				if (front->right != nullptr)
					queue[r++] = front->right;
			}
			ans.push_back(temp);
		}
		return ans;
	}

};
// 2.二叉树的锯齿形层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
class Solution2 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>>ans;
		if (root == nullptr)
			return ans;
		vector<TreeNode*>queue(2000);
		int l = 0, r = 0;
		bool reverse = false;
		queue[r++] = root;
		while (l < r)
		{
			int size = r - l;
			vector<int>temp;
			//将进入队列与收集元素分离
			for (int i = (reverse ? r - 1 : l), k = 0, j = (reverse ? -1 : 1); k < size; i += j,k++)
			{
				temp.push_back(queue[i]->val);
			}
			for (int i = 0; i < size; i++)
			{
				TreeNode* front = queue[l++];
				if (front->left != nullptr)
					queue[r++] = front->left;
				if (front->right != nullptr)
					queue[r++] = front->right;
			}
			ans.push_back(temp);
			reverse = !reverse;
		}

		return ans;
	}
};
// 3.二叉树的最大特殊宽度
// 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/
class Solution3 {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr)
			return 0;
		//按照层序遍历的方式进行遍历
		//维护两个队列，一个维护节点，另一个维护节点的编号
		vector<TreeNode*>queue1(3000);
		vector<unsigned long long>queue2(3000);
		unsigned long long l1 = 0, r1 = 0, l2 = 0, r2 = 0,ans=0;
		//头节点进入队列
		queue1[r1++] = root;
		queue2[r2++] = 1;
		while (l1 < r1)
		{
			int size = r1 - l1;
			ans = max(ans, queue2[r2 - 1] - queue2[l2]+1);
			for (int i = 0; i < size; i++)
			{
				TreeNode* front = queue1[l1++];
				unsigned long long index = queue2[l2++];
				if (front->left != nullptr)
				{
					queue1[r1++] = front->left;
					queue2[r2++] = 2 * index;
				}
				if (front->right != nullptr)
				{
					queue1[r1++] = front->right;
					queue2[r2++] = 2 * index+1;
				}
			}

		}
		return ans;
	}
};
// 4.求二叉树的最大、最小深度
// 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
//求二叉树的最大深度，也就是高度
class Solution4 {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		return f(root);
	}
	int f(TreeNode* root)
	{
		return root == nullptr ? 0 : max(f(root->left), f(root->right)) + 1;
	}
};
//5.求二叉树的最小深度(必须到叶节点）
class Solution5 {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		return f(root);
	}
	int f(TreeNode* root)
	{
		if (root->left == nullptr && root->right == nullptr)
			return  1;
		int leftdepth = 0x7fffffff, rightdepth = 0x7fffffff;
		if (root->left != nullptr);
		leftdepth = f(root->left);
		if (root->right != nullptr)
			rightdepth = f(root->right);
		return min(leftdepth, rightdepth) + 1;
	}
};
//6.// 二叉树先序序列化和反序列化
// 测试链接 : https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
class Codec {
public:
	string serialize(TreeNode* root) {
		string ans;
		f(ans, root);
		return ans;
	}

	void f(string& ans, TreeNode* root) {
		if (root == nullptr) {
			ans += "#,";
			return;
		}
		ans += to_string(root->val) + ",";
		f(ans, root->left);
		f(ans, root->right);
	}

	TreeNode* deserialize(string data) {
		// 使用vector存储分割后的token
		vector<string> tokens;
		string token;
		for (char c : data) {
			if (c == ',') {
				tokens.push_back(token);
				token.clear();
			}
			else {
				token += c;
			}
		}
        counter = 0;
		return g(tokens);
	}

	TreeNode* g(vector<string>& tokens) {
		if ( tokens[counter] == "#") {
			counter++;
			return nullptr;
		}
		TreeNode* root = new TreeNode(stoi(tokens[counter++]));
		root->left = g(tokens);
		root->right = g(tokens);
		return root;
	}

private:
	int counter;
};
int main()
{
	return 0;
}