#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
using namespace std;
// 测试链接 : https://leetcode.cn/problems/sort-an-array/
//1.普通版本(测试链接过不了）
void QuickSort(int l, int r, vector<int>& nums)
{
	if (l >= r)
		return;
	int a = l, i = l, flag = 0;
	static default_random_engine e(time(0));
	uniform_int_distribution<int>u(l, r);
	int val = nums[u(e)];
	while (i <= r)
	{
		if (nums[i] <= val)
		{
			swap(nums[i], nums[a]);
			if (nums[a] == val)
				flag = a;;
			a++, i++;
		}
		else
			i++;
	}
	swap(nums[a - 1], nums[flag]);
	QuickSort(l, a - 2, nums);
	QuickSort(a, r, nums);
}
//2.荷兰国旗优化版本(测试链接可以过)
void Opti_QuickSort(int l, int r, vector<int>& nums)
{
	if (l >= r)
		return;
	static default_random_engine e(time(0));
	uniform_int_distribution<int>u(l, r);
	int val = nums[u(e)];
	int first = l, last = r, i = l;
	while (last >= i)
	{
		if (nums[i] < val)
			swap(nums[first++], nums[i++]);
		else if (nums[i] == val)
			i++;
		else
			swap(nums[i], nums[last--]);
	}
	Opti_QuickSort(l, first - 1, nums);
	Opti_QuickSort(last + 1, r, nums);
}
void checkright(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
}
int main()
{
	for (int times = 0; times < 2000; times++)
	{
		vector<int>nums, temp;
		default_random_engine e(time(0));
		uniform_int_distribution<int>u(-1000, 1000);
		for (int i = 0; i < 500; i++)
			nums.push_back(u(e));
		temp = nums;
		Opti_QuickSort(0, nums.size() - 1, nums);
		checkright(temp);
		if (nums == temp)
		{
			if (times % 100 == 0)
				cout << "第" << times << "测试成功" << endl;
		}
		else
		{
			for (auto p : nums)
				cout << p << " ";
			cout << endl;
			for (auto q : temp)
				cout << q << " ";
		}
	}
	cout << "测试结束" << endl;

	return 0;
}