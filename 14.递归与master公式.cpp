#include<iostream>
#include<vector>
#include<random>
#include<ctime>
using namespace std;
//�õݹ�ķ�ʽ���� �����е����ֵ
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
			cout << "�ɹ���" << endl;
		else
			cout << "ʧ����" << endl;
	}
	return 0;
}
/*
master��ʽ��
a.�����������ģ��ͬ�ĵݹ������master��ʽ��
T(n)=a*T(n/b)+O(n^c),a,b,c���ǳ���
b.���log(b,a)<c,���Ӷȣ�O(n^c)
c.���log(b,a)>c,���Ӷȣ�O(n^log(b,a))
d.���log(b,a)==c,���Ӷȣ�O(n^c*logn)
���䣺
T(n)=2*T(n/2)+O(n*logn),���Ӷȣ�O(n*(logn)^2)
*/

/*
  ����master��ʽ�����
  �����ݹ������ʽΪT(N)=2*(N/2)+O(1)
  ��a=b=2,c=0;  log(b,a)=1>c
  ���Ӷ�ΪO(n)
*/