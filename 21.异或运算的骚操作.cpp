#include<iostream>
#include<random>
#include<ctime>
#include<vector>
using namespace std;
//1.不用比较的方式交换两个数
void myswap(int& a, int& b)
{
	int x = a ^ b;
	a = x ^ a;  //a^b^a =b
	b = x ^ a;   //a^b^b=a
}
// 2.不用比较的方式获得两个数之间的较大值
// 测试链接 : https://www.nowcoder.com/practice/d2707eaf98124f1e8f1d9c18ad487f76
int flag(int x)
{
	return x ^ 1;
}
//因为c++没有无符号右移运算符，只能自己手写
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
int sign(int a)
{
	return flag(unsignmove(a, 31));
}
int getmax1(int a, int b)  //存在溢出风险
{
	int c = a - b;
	int returnA = sign(c);
	int returnB = flag(returnA);
	return (a * returnA + b * returnB);
}
int getmax2(int a, int b)  //不存在溢出风险
{
	//获得a,b,c的符号
	int c = a - b;
	int sa = sign(a), sb = sign(b), sc = sign(c);
	int diffAB = sa ^ sb;
	int sameAB = flag(diffAB);
	/*
	若a,b两数符号相同，则不存在溢出风险
	若不同存在溢出风险，根据符号是否相同进行判断
	*/
	int returnA = diffAB * sa + sameAB * sc;
	int returnB = flag(returnA);
	return a * returnA + b * returnB;
}

//3. 找到缺失的数字
// 测试链接 : https://leetcode.cn/problems/missing-number/
class Solution1 {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int res1 = 0,res2=0;
		for (auto p : nums)
			res1 ^= p;
		for (int i = 0; i <= n; i++)
			res2 ^= i;
		return res1 ^ res2;
	}
};
//4.// 数组中1种数出现了奇数次，其他的数都出现了偶数次
// 返回出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number/
class Solution2 {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (auto p : nums)
			ans ^= p;
		return ans;
	}
};
//5.// 数组中有2种数出现了奇数次，其他的数都出现了偶数次
// 返回这2种出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number-iii/
class Solution3 {
public:
	long long lowbit(long long x)
	{
		return x & (-x);
	}
	vector<int> singleNumber(vector<int>& nums) {
		//这题出的比较毒，要用long long来接收
		long long res1 = 0;
		for (auto p : nums)
			res1 ^= p;  //此时res1=a^b
		long long res2 = lowbit(res1);
		long long res3 = 0;
		for (auto p : nums)
		{
			if ((p & res2) != 0)
				res3 ^= p;
		}
		vector<int>ans;
		ans.push_back(res3);
		ans.push_back(res3 ^ res1);
		return ans;
	}
};
//6.// 数组中只有1种数出现次数少于m次，其他数都出现了m次
// 返回出现次数小于m次的那种数
// 测试链接 : https://leetcode.cn/problems/single-number-ii/
class Solution5 {
public:
	int singleNumber(vector<int>& nums) {
		vector<int>cnts(32);
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < 32; j++)
				if ((nums[i] & (1 << j)) != 0)
					cnts[j]++;
		}
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			if (cnts[i] % 3 != 0)
				ans |= 1 << i;
		}
		return ans;
	}
};

int main()
{
	for (int k = 0; k < 2000; k++)
	{
		default_random_engine e(time(0));
		uniform_int_distribution<int>u(-100, 100);
		int a = u(e), b = u(e);
		if (getmax2(a, b) == max(a, b))
		{
			if (k % 100 == 0)
				cout << "第" << k << "组测试成功" << endl;
		}
		else
		{
			cout << "测试失败" << endl;
			cout << a << " " << b << endl;
			cout << "getmax" << getmax2(a, b) << endl;
			cout << "max" << max(a, b) << endl;
		}
	}
	return 0;
}