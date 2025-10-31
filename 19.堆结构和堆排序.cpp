#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<algorithm>
using namespace std;
//用数组实现大根堆(小根堆改个大小于号即可）
vector<int>heap;
int heapsize;
void HeapInsert(int i)
{
	while (heap[i] > heap[(i - 1) / 2])
	{
		swap(heap[i], heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}
void Heapify(int i)
{
	while (2 * i + 1 < heapsize)
	{
		int l = 2 * i + 1;
		int best = l + 1 < heapsize && heap[l + 1] > heap[l] ? l + 1 : l;
		best = heap[best] > heap[i] ? best : i;
		if (i == best)
			break;
		swap(heap[best], heap[i]);
		i = best;
	}
}
void checkright(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
}
int main()
{
	for (int cnt = 0; cnt < 2000; cnt++)
	{
		static default_random_engine e(time(0));
		uniform_int_distribution<int>u(-100, 100);
		heap.resize(1000);
		for (int i = 0; i < 1000; i++)
			heap[i] = u(e);
		vector<int>temp = heap;
		for (int i = 0; i < 1000; i++)
		{
			heapsize++;
			HeapInsert(i);
		}
		while (heapsize)
		{
			swap(heap[0], heap[--heapsize]);
			Heapify(0);
		}
		checkright(temp);
		if (temp == heap)
		{
			if (cnt % 100 == 0)
				cout << "第" << cnt << "组测试成功" << endl;
		}
		else
		{
			cout << "测试失败" << endl;
		}
	}
	return 0;
}