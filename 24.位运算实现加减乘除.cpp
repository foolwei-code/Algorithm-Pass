#include<iostream>
#include<vector>
#include<random>
#include<climits>
using namespace std;
//测试链接：https://leetcode.cn/problems/divide-two-integers/
class Solution {
public:
	int divide(int dividend, int divisor) {
		int min_int = INT_MIN;
		if (dividend == min_int && divisor == min_int)
			return 1;
		if (dividend != min_int && divisor != min_int)
			return div(dividend, divisor);
		if (divisor == min_int)
			return 0;
		if (divisor == -1)
			return INT_MAX;
		dividend = add(dividend, divisor > 0 ? divisor : neg(divisor));
		int ans = div(dividend, divisor);
		int offset = divisor > 0 ? neg(1) : 1;
		return add(ans, offset);
	}
	//1.位运算实现加法
	int add(int a, int b)
	{
		int ans, carry;
		ans = a ^ b;  //a与b无进位相加
		carry = a & b;  //获取进位信息
		while (carry)
		{
			int temp = ans;
			ans ^= (carry << 1);
			carry = temp & (carry << 1);
		}
		return ans;
	}
	//2.位运算实现减法
	//获得a的相反数-a=~a+1
	int neg(int a)
	{
		return add(~a, 1);
	}
	int sub(int a, int b)
	{
		//a-b就是a+(-b)
		return add(a, neg(b));
	}
	//3.位运算实现乘法
	int unsignmove(int x, int bit)//进行无符号右移
	{
		if (x >= 0)
			return x >> bit;
		else
		{
			x >>= bit;
			for (int i = 0; i < bit; i++)
				x ^= (1 << 31 - i);
		}
		return x;
	}
	int mul(int a, int b)
	{
		if (a == 0 || b == 0)
			return 0;
		int ans = 0;
		while (b != 0)
		{
			if ((b & 1) != 0)
				ans = add(ans, a);
			a <<= 1;
			b = unsignmove(b, 1);
		}
		return ans;
	}
	//用位运算实现除法
	int div(int a, int b)//a,b不能是整数最小值
	{
		int ans = 0;
		int x = a < 0 ? neg(a) : a;
		int y = b < 0 ? neg(b) : b;
		for (int i = 30; i >= 0; i = sub(i, 1))
		{
			if ((x >> i) >= y)
			{
				ans |= 1 << i;
				x = sub(x, (y << i));
			}
		}
		return ((a < 0) ^ (b < 0)) ? neg(ans) : ans;
	}
};
int main()
{
	Solution p;
	for (int k = 0; k < 2000; k++)
	{
		default_random_engine e(time(0));
		uniform_int_distribution<int>u(-10000, 10000);
		int a = u(e), b = u(e);
		if (p.div(a, b) == a / b)
		{
			if (k % 100 == 0)
				cout << "第" << k << "组测试成功" << endl;
		}
		else
		{
			cout << "测试失败" << endl;
		}
	}
	return 0;
}