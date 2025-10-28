#include<iostream>
#include<vector>
using namespace std;
//1.小和问题
// 测试链接 : https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
vector<int>arr, help;
int n;
long long merge(int l, int mid, int r)
{
	int left = l, right = mid + 1;
	long long ans = 0;
	for (int i = left, j = right, sum = 0; j <= r; j++)
	{
		while (i <= mid && arr[i] <= arr[j])
			sum += arr[i++];
		ans += sum;
	}
	//合并
	int k = left;
	while (left <= mid && right <= r)
	{
		if (arr[left] <= arr[right])
			help[k++] = arr[left++];
		else
			help[k++] = arr[right++];
	}
	while (left <= mid)
		help[k++] = arr[left++];
	while (right <= r)
		help[k++] = arr[right++];
	//还原给原数组
	for (int i = l; i <= r; i++)
		arr[i] = help[i];
	return ans;
}
long long smallsum(int l, int r)
{
	if (l == r)
		return 0;
	int mid = l + ((r - l) >> 1);
	return smallsum(l, mid) + smallsum(mid + 1, r) + merge(l, mid, r);
}

// 翻转对数量
// 测试链接 : https://leetcode.cn/problems/reverse-pairs/
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		vector<int>help(n);
		return getpairs(0, n - 1, help,nums);
	}
	int getpairs(int l, int r, vector<int>& help, vector<int>& nums)
	{
		if (l == r)
			return 0;
		int mid = l + ((r - l) >> 1);
		return getpairs(l, mid, help, nums) + getpairs(mid + 1, r, help, nums) + merge(l, mid, r, help, nums);
	}
	int merge(int l, int mid, int r, vector<int>& help, vector<int>& nums)
	{
		int ans = 0;
		for (int i = l, j = mid + 1, sum = 0; i <= mid; i++)
		{
			while (j<=r && nums[i] > 2 * (long long)nums[j])//细节
				sum++, j++;
			ans += sum;
		}
		//合并
		int left = l, right = mid+1;
		int k = left;
		while (left <= mid && right <= r)
		{
			if (nums[left] <= nums[right])
				help[k++] = nums[left++];
			else
				help[k++] = nums[right++];
		}
		while (left <= mid)
			help[k++] = nums[left++];
		while (right <= r)
			help[k++] = nums[right++];
		//还原给原数组
		for (int i = l; i <= r; i++)
			nums[i] = help[i];
		return ans;
	}
};
int main()
{
	cin >> n;
	int num;
	help.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	cout << smallsum(0, arr.size() - 1);
	return 0;
}