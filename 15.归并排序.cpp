#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<algorithm>
using namespace std;
// 测试链接 : https://leetcode.cn/problems/sort-an-array/
void MergeSort(vector<int>& arr, int l, int r, vector<int>& help)
{
	if (l == r)
		return;
	int mid = l + ((r - l) >> 1);
	MergeSort(arr, l, mid, help);
	MergeSort(arr, mid + 1, r, help);
	int left = l, right = mid + 1, k = left;
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
	//还原给元素组
	for (int i = l; i <= r; i++)
		arr[i] = help[i];
}
int main()
{
	for (int k = 0; k < 20; k++)
	{
		vector<int>arr, temp, help;
		default_random_engine e(time(0));
		uniform_int_distribution<int>u(-1000, 1000);
		for (int i = 0; i < 1000; i++)
		{
			arr.push_back(u(e));
		}
		temp = arr;
		help.resize(arr.size());
		sort(temp.begin(), temp.end());
		MergeSort(arr, 0, arr.size() - 1, help);
		if (arr == temp)
			cout << "成功了" << endl;
		else
			cout << "失败了" << endl;
	}
	return 0;
}