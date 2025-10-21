#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<ctime>
using namespace std;
class Solution1
{
public:
	//һ.�����������в��Ҵ治����num
	//1.���ַ�����
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
	//2.��������֤
	bool checkright1(vector<int>& arr, int num)
	{
		for (auto p : arr)
			if (p == num)
				return true;
		return false;
	}
	//��.�����������в���С�ڵ���num���Ҳ��ֵ���±꣬û�з���-1
	//1.��������
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
	//2.��������֤
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
	//��.�����������в��Ҵ��ڵ���num������ֵ���±꣬û�з���-1
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
	//��������֤
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
//�������� : https://leetcode.cn/problems/find-peak-element/
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
	//������֤
	for (int k = 0; k < 10; k++)
	{
		vector<int>arr;
		default_random_engine e(time(0));
		uniform_int_distribution<int>u(-100, 100);
		int num = u(e);
		for (int i = 0; i < 1000; i++)
			arr.push_back(u(e));
		//��������
		sort(arr.begin(), arr.end());
		Solution1 p;
		if (p.find_number(arr, num) == p.checkright1(arr, num))
			cout << "�ɹ���" << endl;
		else
			cout << "ʧ����" << endl;
		if (p.find_rightindex(arr, num) == p.checkright2(arr, num))
			cout << "�ɹ���" << endl;
		else
			cout << "ʧ����" << endl;
		if (p.find_leftindex(arr, num) == p.checkright3(arr, num))
			cout << "�ɹ���" << endl;
		else
			cout << "ʧ����" << endl;
	}
 
    return 0;
}