#include<iostream>
#include<vector>
#include<limits>
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
// 4.验证平衡二叉树
// 测试链接 : https://leetcode.cn/problems/balanced-binary-tree/
class Solution4 {
public:
	bool isBalanced(TreeNode* root) {
		 balance = true;
		height(root);
		return balance;
	}
	int height(TreeNode* root)
	{
		if (root == nullptr || !balance)
			return 0;
		int leftheight = height(root->left);
		int rightheight = height(root->right);
		if (abs(leftheight - rightheight) > 1)
			balance = false;
		return max(leftheight, rightheight) + 1;
	}
private:
	bool balance;
};
// 5.验证搜索二叉树
// 测试链接 : https://leetcode.cn/problems/validate-binary-search-tree/
class Solution5 {
public:
	bool isValidBST(TreeNode* root) {
		//way1:将该二叉树进行中序遍历，验证该序列是否是一个上升序列
		//vector<int>arr;
		/*f1(root, arr);
		for (int i = 0; i < arr.size() - 1; i++)
			if (arr[i] >=arr[i + 1])
				return false;
		return true;*/
		//way2:树形dp
		return f2(root);
	}
	void f1(TreeNode* root, vector<int>& arr)
	{
		if (root == nullptr)
			return;
		f1(root->left, arr);
		arr.push_back(root->val);
		f1(root->right, arr);
	}
	bool f2(TreeNode* root)
	{
		if (root == nullptr)
		{
			minnum = numeric_limits<long long>::max();
			maxnum = numeric_limits<long long>::min();
			return true;
		}
		bool lok = f2(root->left);
		long long lmax = maxnum;
		long long lmin = minnum;
		bool rok = f2(root->right);
		long long rmax = maxnum;
		long long rmin = minnum;
		//将maxnum与minnum进行修正
		maxnum = mymax(mymax(lmax, rmax), root->val);
		minnum = mymin(mymin(lmin, rmin), root->val);
		return lok && rok && ((lmax < root->val) && (root->val < rmin));
	}
	long long mymax(long long a, long long b)
	{
		return a > b ? a : b;
	}
	long long mymin(long long a, long long b)
	{
		return a > b ? b : a;
	}
private:
	long long minnum;
	long long maxnum;
};
//6.修剪搜索二叉树
// 测试链接 : https://leetcode.cn/problems/trim-a-binary-search-tree/
class Solution6 {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (root == nullptr)
			return nullptr;
		if (root->val > high)
			return trimBST(root->left, low, high);
		if (root->val < low)
			return trimBST(root->right, low, high);
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}
};
// 7.二叉树打家劫舍问题
// 测试链接 : https://leetcode.cn/problems/house-robber-iii/
class Solution7 {
public:
	//way1:暴力递归：时间复杂度太高，测试用例通过不了
	int rob1(TreeNode* root) {
		if (root == nullptr)
			return 0;
		//以选不选根节点作为划分标准
		//1.不选根节点
		int num1 = rob1(root->left) + rob1(root->right);
		//2.选根节点
		int num2 = root->val;
		num2 += (root->left == nullptr ? 0 : rob1(root->left->left) + rob1(root->left->right));
		num2 += (root->right == nullptr ? 0 : rob1(root->right->left) + rob1(root->right->right));
		return max(num1, num2);
	}
	int rob(TreeNode* root)
	{
		f(root);
		return max(yes, no);
	}
	void f(TreeNode* root)
	{
		if (root == nullptr)
		{
			yes = 0, no = 0;
			return;
		}
		//同样以选不选根节点作为标准
		int x = root->val,y=0;
		f(root->left);
		x += no;
		y += max(yes, no);
		f(root->right);
		x += no;
		y += max(yes, no);
		yes = x;
		no = y;
	}
private:
	int yes;  //yes表示要当前根节点的最大值
	int no;   //no表示不要当前根节点的最大值
};
int main()
{

	return 0;
}
