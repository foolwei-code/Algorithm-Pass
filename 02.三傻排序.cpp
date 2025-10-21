//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<random>
//#include<ctime>
//using namespace std;
//class Solution
//{
//public:
//	//1.冒泡排序
//	vector<int>BubbleSort(vector<int>nums)
//	{
//		int n = nums.size();
//		for (int i = n - 1; i >= 1; i--)
//		{
//			for (int j = 0; j < i; j++)
//			{
//				if (nums[j] > nums[j+1])
//					swap(nums[j], nums[j+1]);
//			}
//		}
//		return nums;
//	}
//	//2.选择排序
//	vector<int>SelectSort(vector<int>nums)
//	{
//		int n = nums.size();
//		for (int i = 0; i < n-1; i++)
//		{
//			for (int j = i + 1; j < n; j++)
//			{
//				if (nums[i] > nums[j])
//					swap(nums[i], nums[j]);
//			}
//		}
//		return nums;
//	}
//	//3.插入排序
//	vector<int>InsertSort(vector<int>nums)
//	{
//		int n = nums.size();
//		for (int i = 0; i < n; i++)
//		{
//			int cnt = i;
//			while (cnt - 1 >= 0 && nums[cnt] < nums[cnt - 1])
//			{
//				swap(nums[cnt], nums[cnt - 1]);
//				cnt--;
//			}
//		}
//		return nums;
//	}
//	//对数器验证
//	vector<int>checkright(vector<int>nums)
//	{
//		sort(nums.begin(), nums.end());
//		return nums;
//	}
//};
//int main()
//{
//	//设置验证次数
//	for (int k = 0; k < 10; k++)
//	{	//生成随机数组
//		vector<int>nums;
//		default_random_engine e(time(0));
//		uniform_int_distribution<int>u(-1000, 1000);  //随机数范围
//		for (int i = 0; i < 10; i++)
//		{
//			nums.push_back(u(e));
//		}
//		Solution p;
//		//1.验证冒泡排序
//		if (p.BubbleSort(nums) == p.checkright(nums))
//			cout << "成功了" << endl;
//		else
//			cout << "失败了" << endl;
//		//2.验证选择排序
//		if (p.SelectSort(nums) == p.checkright(nums))
//			cout << "成功了" << endl;
//		else
//			cout << "失败了" << endl;
//		//3.验证插入排序
//		if (p.InsertSort(nums) == p.checkright(nums))
//			cout << "成功了" << endl;
//		else
//			cout << "失败了" << endl;
//	}
//	return 0;
//}