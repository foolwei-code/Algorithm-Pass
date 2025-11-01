#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<ctime>
#define INF 0x7fffffff
using namespace std;
// 测试链接 : https://leetcode.cn/problems/sort-an-array/
int getbit(int x)
{
	if (x == 0)
		return 1;
	int ans = 0;
	while (x != 0)
	{
		ans++; x /= 10;
	}
	return ans;
}
void RadixSort(vector<int>& nums, vector<int>& help)
{
	const int BASE = 10;
	vector<int>cnts(BASE);
	int maxnum = -INF;
	for (auto p : nums)
		maxnum = max(maxnum, p);
	//获得最大值的位数
	int bit = getbit(maxnum);
	int offset = 1;
	while (bit > 0)
	{
		//对cnts进行清空
		for (int i = 0; i < BASE; i++)
			cnts[i] = 0;
		for (int i = 0; i < nums.size(); i++)
			cnts[(nums[i] / offset) % BASE]++;
		for (int i = 1; i <= BASE - 1; i++)
			cnts[i] += cnts[i - 1];
		//倒序遍历数组
		for (int i = nums.size() - 1; i >= 0; i--)
			help[--cnts[(nums[i] / offset) % BASE]] = nums[i];
		//还原给原数组
		for (int i = 0; i < nums.size(); i++)
			nums[i] = help[i];
		bit--, offset *= BASE;
	}
}
void checkright(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
}
int main()
{
	for (int k = 0; k < 2000; k++)
	{
		vector<int>nums;
		default_random_engine e(time(0));
		uniform_int_distribution<int> u(0, 1000);
		for (int i = 0; i < 1000; i++)
			nums.push_back(u(e));
		vector<int>temp = nums;
		vector<int>help(nums.size());
		RadixSort(nums, help);
		checkright(temp);
		if (temp == nums)
		{
			if (k % 100 == 0)
				cout << "第" << k << "组测试成功" << endl;
		}
		else
			cout << "测试失败" << endl;
	}
	return 0;
}