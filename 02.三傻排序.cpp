//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<random>
//#include<ctime>
//using namespace std;
//class Solution
//{
//public:
//	//1.ð������
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
//	//2.ѡ������
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
//	//3.��������
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
//	//��������֤
//	vector<int>checkright(vector<int>nums)
//	{
//		sort(nums.begin(), nums.end());
//		return nums;
//	}
//};
//int main()
//{
//	//������֤����
//	for (int k = 0; k < 10; k++)
//	{	//�����������
//		vector<int>nums;
//		default_random_engine e(time(0));
//		uniform_int_distribution<int>u(-1000, 1000);  //�������Χ
//		for (int i = 0; i < 10; i++)
//		{
//			nums.push_back(u(e));
//		}
//		Solution p;
//		//1.��֤ð������
//		if (p.BubbleSort(nums) == p.checkright(nums))
//			cout << "�ɹ���" << endl;
//		else
//			cout << "ʧ����" << endl;
//		//2.��֤ѡ������
//		if (p.SelectSort(nums) == p.checkright(nums))
//			cout << "�ɹ���" << endl;
//		else
//			cout << "ʧ����" << endl;
//		//3.��֤��������
//		if (p.InsertSort(nums) == p.checkright(nums))
//			cout << "�ɹ���" << endl;
//		else
//			cout << "ʧ����" << endl;
//	}
//	return 0;
//}