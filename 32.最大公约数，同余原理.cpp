#include<iostream>
//1.用辗转相除法求gcd与lcm
class Solution1
{
public:
	int gcd(int a,int b)
	{
		return b==0?a:gcd(b, a % b);
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
		long long l = std::min(a,b), r = n * lcm_num, ans = 0;
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