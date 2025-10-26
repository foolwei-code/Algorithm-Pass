#include<iostream>
#include<vector>
#include<random>
#include<ctime>
using namespace std;
//用递归的方式查找 数组中的最大值
vector<int>arr;
const int INF = 0x7fffffff;
int f(int l, int r)
{
	if (l == r)
		return  arr[l];
	int mid = l + ((r - l) >> 1);
	int num1 = f(l, mid);
	int num2 = f(mid + 1, r);
	return max(num1, num2);
}
int checkright()
{
	int ans = -INF;
	for (auto p : arr)
		ans = max(ans, p);
	return ans;
}
int main()
{
	for (int k = 0; k < 20; k++)
	{
		default_random_engine e(time(0));
		uniform_int_distribution<int>u(-10000, 10000);
		for (int i = 0; i < 1000; i++)
			arr.push_back(u(e));
		int n = arr.size();
		if (f(0, n - 1) == checkright())
			cout << "成功了" << endl;
		else
			cout << "失败了" << endl;
	}
	return 0;
}
/*
master公式：
a.所有子问题规模相同的递归才能用master公式，
T(n)=a*T(n/b)+O(n^c),a,b,c都是常数
b.如果log(b,a)<c,复杂度：O(n^c)
c.如果log(b,a)>c,复杂度：O(n^log(b,a))
d.如果log(b,a)==c,复杂度：O(n^c*logn)
补充：
T(n)=2*T(n/2)+O(n*logn),复杂度：O(n*(logn)^2)
*/

/*
  按照master公式所理解
  上述递归代码表达式为T(N)=2*(N/2)+O(1)
  即a=b=2,c=0;  log(b,a)=1>c
  复杂度为O(n)
*/