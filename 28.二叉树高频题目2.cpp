#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
//1.普通二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution1 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left == nullptr && right == nullptr)
			return nullptr;
		if (left != nullptr && right != nullptr)
			return root;
		//剩下的一个肯定为空，另一个不为空，返回不空的那个
		return left == nullptr ? right : left;
	}
};
// 2.搜索二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
class Solution2 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// root从上到下
		// 如果先遇到了p，说明p是答案
		// 如果先遇到了q，说明q是答案
		// 如果root在p~q的值之间，不用管p和q谁大谁小，只要root在中间，那么此时的root就是答案
		// 如果root在p~q的值的左侧，那么root往右移动
		// 如果root在p~q的值的右侧，那么root往左移动
		while (root->val != p->val && root->val != q->val) {
			if (min(p->val, q->val) < root->val && root->val < max(p->val, q->val)) {
				break;
			}
			root = root->val < min(p->val, q->val) ? root->right : root->left;
		}
		return root;
	}
};
// 3.收集累加和等于aim的所有路径
// 测试链接 : https://leetcode.cn/problems/path-sum-ii/
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>>ans;
		if (root == nullptr)
			return ans;
		f(root, ans, targetSum,0);
		return ans;
	}
	void f(TreeNode* root, vector<vector<int>>& ans, int targetsum, int sum)
	{
		if (root->left== nullptr&&root->right==nullptr)
		{
			if (sum+root->val== targetsum)
			{
				path.push_back(root->val);
				ans.push_back(path);
				path.pop_back();
			}
			return;
		}
		path.push_back(root->val);
		if(root->left!=nullptr)
		f(root->left, ans, targetsum, sum + root->val);
		if(root->right!=nullptr)
		f(root->right, ans, targetsum, sum + root->val);
		path.pop_back();
	}
private:
	vector<int>path;
};
int main()
{

	return 0;
}
