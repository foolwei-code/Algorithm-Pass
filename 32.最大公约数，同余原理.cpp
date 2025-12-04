#include<iostream>
#include<random>
#include<ctime>
//1.用辗转相除法求gcd与lcm
using namespace std;
class Solution1
{
public:
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
	int lcm(int a, int b)
	{
		return (long long)a / gcd(a, b) * b;
	}
};
// 2.一个正整数如果能被 a 或 b 整除，那么它是神奇的。
// 给定三个整数 n , a , b ，返回第 n 个神奇的数字。
// 因为答案可能很大，所以返回答案 对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/nth-magical-number/
class Solution2
{
public:
	int nthMagicalNumber(int n, int a, int b) {
		long long lcm_num = lcm(a, b);
		long long l = std::min(a, b), r = n * lcm_num, ans = 0;
		while (l <= r)
		{
			long long mid = l + ((r - l) >> 1);
			if (mid / a + mid / b - mid / lcm_num >= n)
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		return ans % 1000000007;
	}
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
	int lcm(int a, int b)
	{
		return (long long)a / gcd(a, b) * b;
	}
};

//3.同余原理
class Solution3
{
public:
	// 计算 ((a + b) * (c - d) + (a * c - b * d)) % mod 的非负结果
	int f1(int a, int b, int c, int d, int mod)
	{
		long long la = a, lb = b, lc = c, ld = d, lmod = mod;  //防止溢出
		long long ans = ((la + b) * (lc - ld) + (la * lc - lb * ld)) % lmod;
		if (ans < 0)
			ans += lmod;
		return ans;
	}
	int f2(int a, int b, int c, int d, int mod)
	{
		a %= mod, b %= mod, c %= mod, d %= mod;
		int ans = (a + b) % mod;
		int temp1 = (c - d + mod) % mod;
		ans = (ans * temp1) % mod;
		temp1 = (a * c) % mod;
		int temp2 = (b * d) % mod;
		temp1 = (temp1 - temp2 + mod) % mod;
		return (ans + temp1) % mod;
	}
};
int main()
{
	for (int i = 0; i < 2000; i++)
	{
		static default_random_engine e(time(0));
		static uniform_int_distribution<int>u(0, 10000);
		Solution3 p;
		int a = u(e), b = u(e), c = u(e), d = u(e), mod = u(e);
		if (p.f1(a, b, c, d, mod) == p.f2(a, b, c, d, mod))
		{
			if (i % 100 == 0)
				cout << "成功了" << endl;
		}
		else
			cout << "失败了" << endl;
	}
	return 0;
}