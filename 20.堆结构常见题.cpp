#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
//1.合并K个升序链表
// 测试链接：https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6
//https://leetcode.cn/problems/merge-k-sorted-lists/description/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
struct cmp
{
	bool operator()(ListNode*& a, ListNode*& b)const
	{
		return a->val > b->val;
	}
};
class Solution1 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return nullptr;
		priority_queue<ListNode*, vector<ListNode*>, cmp>heap;
		//将lists中的所有表头全部进入堆中
		for (int i = 0; i < lists.size(); i++)
			if(lists[i]!=nullptr)
			heap.push(lists[i]);
		if (heap.empty())
			return nullptr;
		ListNode* head = nullptr, * cur = nullptr;
		//事先处理头节点
		head = cur = heap.top();
		heap.pop();
		if (cur->next != nullptr)
			heap.push(cur->next);
		while (!heap.empty())
		{
			ListNode* top = heap.top();
			heap.pop();
			cur->next = top;
			if (top->next != nullptr)
				heap.push(top->next);
			cur = cur->next;
		}
		return head;
	}
};
//2. 最多线段重合问题
// 测试链接 : https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
size_t  n,ans;   //这里主要是因为ans要与size()比较，两者类型要兼容
const int N = 1e4 + 5;
vector<vector<int>>lines(N, vector<int>(2, 0));
struct cmp
{
	bool operator()(vector<int>& a, vector<int>& b)const
	{
		return a[0] < b[0];
	}
};
// 3.将数组和减半的最少操作次数
// 测试链接 : https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/
class Solution2 {
public:
	int halveArray(vector<int>& nums) {
		int ans = 0;
		double sum = 0;
		priority_queue<double>heap;
		for (int p : nums)
		{
			heap.push((double)p);
			sum += p;
		}
		double temp = sum;
		while (temp > sum / 2)
		{
			double top = heap.top();
			heap.pop();
			top /= 2, ans++;
			temp -= top;
			heap.push(top);
		}
		return ans;
	}
};
int main()
{
	cin >> n;
	lines.resize(n);
	priority_queue<int,vector<int>,greater<int>>heap;
	for (int i = 0; i < n; i++)
		cin >> lines[i][0] >> lines[i][1];
	sort(lines.begin(), lines.end(), cmp());
	//枚举每一条线段
	for (int i = 0; i < n; i++)
	{
		while (!heap.empty() && heap.top() <=lines[i][0])
			heap.pop();
		heap.push(lines[i][1]);
		ans = max(ans, heap.size());
	}
		return 0;
}