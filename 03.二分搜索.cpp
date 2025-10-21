#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<ctime>
using namespace std;
class Solution1
{
public:
	//一.在有序数组中查找存不存在num
	//1.二分法查找
	bool find_number(vector<int>& arr, int num)
	{
		int n = arr.size();
		int l = 0, r = n - 1;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (arr[mid] > num)
				r = mid - 1;
			else if (arr[mid] == num)
				return true;
			else
				l = mid + 1;
		}
		return false;
	}
	//2.对数器验证
	bool checkright1(vector<int>& arr, int num)
	{
		for (auto p : arr)
			if (p == num)
				return true;
		return false;
	}
	//二.在有序数组中查找小于等于num最右侧的值的下标，没有返回-1
	//1.二分搜索
	int find_rightindex(vector<int>& arr, int num)
	{
		int n = arr.size();
		int l = 0, r = n - 1;
		int ans = -1;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (arr[mid] <= num)
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		return ans;
	}
	//2.对数器验证
	int checkright2(vector<int>& arr, int num)
	{
		int ans = -1;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] <= num)
				ans = i;
		}
		return ans;
	}
	//三.在有序数组中查找大于等于num最左侧的值的下标，没有返回-1
	int find_leftindex(vector<int>& arr, int num)
	{
		int n = arr.size();
		int l = 0, r = n - 1;
		int ans = -1;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (arr[mid] >= num)
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		return ans;
	}
	//对数器验证
	int checkright3(vector<int>& arr, int num)
	{
		int ans = -1;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] >=num)
			{
				ans = i;
				break;
			}
		  }
		return ans;
	}
};
//测试链接 : https://leetcode.cn/problems/find-peak-element/
class Solution2
{
 public:
	 int f(int l, int r, vector<int>& nums)
	 {
		 int ans = -1;
		 while (l <= r)
		 {
			 int mid = l + ((r - l) >> 1);
			 if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
			 {
				 ans = mid;
				 break;
			 }
			 else if (nums[mid] > nums[mid - 1] && nums[mid + 1] > nums[mid])
				 l = mid + 1;
			 else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1])
				 r = mid - 1;
			 else
				 l = mid + 1;
		 }
		 return ans;
	 }
	 int findPeakElement(vector<int>& nums)
	 {
		 int n = nums.size();
		 if (n == 1)
			 return 0;
		 if (nums[0] > nums[1])
			 return 0;
		 if (nums[n - 1] > nums[n - 2])
			 return n - 1;
		 return f(1, n - 2,nums);
	 }

};
int main()
{
	//进行验证
	for (int k = 0; k < 10; k++)
	{
		vector<int>arr;
		default_random_engine e(time(0));
		uniform_int_distribution<int>u(-100, 100);
		int num = u(e);
		for (int i = 0; i < 1000; i++)
			arr.push_back(u(e));
		//进行排序
		sort(arr.begin(), arr.end());
		Solution1 p;
		if (p.find_number(arr, num) == p.checkright1(arr, num))
			cout << "成功了" << endl;
		else
			cout << "失败了" << endl;
		if (p.find_rightindex(arr, num) == p.checkright2(arr, num))
			cout << "成功了" << endl;
		else
			cout << "失败了" << endl;
		if (p.find_leftindex(arr, num) == p.checkright3(arr, num))
			cout << "成功了" << endl;
		else
			cout << "失败了" << endl;
	}
 
    return 0;
}