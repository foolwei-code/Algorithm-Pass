// 1.现在有一个打怪类型的游戏，这个游戏是这样的，你有n个技能
// 每一个技能会有一个伤害，
// 同时若怪物小于等于一定的血量，则该技能可能造成双倍伤害
// 每一个技能最多只能释放一次，已知怪物有m点血量
// 现在想问你最少用几个技能能消灭掉他(血量小于等于0)
// 技能的数量是n，怪物的血量是m
// i号技能的伤害是x[i]，i号技能触发双倍伤害的血量最小值是y[i]
// 1 <= n <= 10
// 1 <= m、x[i]、y[i] <= 10^6
// 测试链接 : https://www.nowcoder.com/practice/d88ef50f8dab4850be8cd4b95514bbbd
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int cnt, skills, blood;
const int N = 15;
int attacks[N], conditions[N];
void myswap(int i, int j)
{
	swap(attacks[i], attacks[j]);
	swap(conditions[i], conditions[j]);
}
int f(int i, int j)
{
	if (j <= 0)
		return 0;
	if (i == skills + 1)
		return numeric_limits<int>::max();
	int ans = numeric_limits<int>::max();
	for (int k = i; k <= skills; k++)
	{
		myswap(i, k);
		int temp = j;
		j = (conditions[i] >= j) ? (j - 2 * attacks[i]) : (j - attacks[i]);
		int res = f(i + 1, j);
		if (res != numeric_limits<int>::max())
			ans = min(ans, res + 1);
		//恢复现场
		myswap(i, k);
		j = temp;
	}
	return ans;
}

//2.// 超级回文数(java版)
// 如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为超级回文数。
// 现在，给定两个正整数 L 和 R （以字符串形式表示），
// 返回包含在范围 [L, R] 中的超级回文数的数目。
// 1 <= len(L) <= 18
// 1 <= len(R) <= 18
// L 和 R 是表示 [1, 10^18) 范围的整数的字符串
//测试链接 : https://leetcode.cn/problems/super-palindromes/
class Solution {
public:
	int superpalindromesInRange(string left, string right) {
		long long l = stoll(left);
		long long r = stoll(right);
		long long limit = (long long)sqrt((double)r);
		long long ans = 0, num = 0, seed = 1;
		   while(num<limit)
		   {
			num = even(seed);
			if (num<=limit&&check(num, l, r))
				ans++;
			num = odd(seed);
			if (num<=limit&&check(num, l, r))
				ans++;
			seed++;
		} 
		return ans;
	}
	//生成偶数个数的回文数
	long long even(long long num)
	{
		long long temp = num;
		while (temp != 0)
		{
			num = num * 10 + (temp % 10);
			temp /= 10;
		}
		return num;
	}
	long long odd(long long num)
	{
		long long temp = num / 10;
		while (temp != 0)
		{
			num = num * 10 + (temp % 10);
			temp /= 10;
		}
		return num;
	}
	bool check(long long num,long long left,long long right)
	{
		long long temp = num * num;
		if (temp<left || temp>right)
			return false;
		string s = to_string(temp);
		int l = 0, r = s.size() - 1;
		while (l <= r)
			if (s[l++] != s[r--])
				return false;
		return true;
	}
};

int main()
{
	cin >> cnt;
	while (cnt--)
	{
		cin >> skills >> blood;
		for (int i = 1; i <=skills; i++)
			cin >> attacks[i] >> conditions[i];
		//f(i,j)表示从第i开始选，剩余血量还剩j的使用的最少技能数
		int ans = f(1, blood);
		cout << (ans == numeric_limits<int>::max() ? -1 : ans) << endl;
	}
	return 0;
}