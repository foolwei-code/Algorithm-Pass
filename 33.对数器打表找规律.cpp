#include<iostream>
using namespace std;
// 1.有装下8个苹果的袋子、装下6个苹果的袋子，一定要保证买苹果时所有使用的袋子都装满
// 对于无法装满所有袋子的方案不予考虑，给定n个苹果，返回至少要多少个袋子
// 如果不存在每个袋子都装满的方案返回-1
class Solution1
{
public:
    int CalculateNumber1(int n)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return -1;
        int ans = 0;
        //选择用大小为6的袋子来装苹果
        int res1 = CalculateNumber1(n - 6);
        //选择用大小为8的袋子来装苹果
        int res2 = CalculateNumber1(n - 8);
        if (res1 != -1 && res2 != -1)
            ans = min(res1, res2) + 1;
        else if (res1 == -1 && res2 == -1)
            ans = -1;
        else
            ans = res1 == -1 ? res2 + 1 : res1 + 1;

        return ans;
    }
    int CalculateNumber2(int n)
    {
        if ((n & 1) == 1)
            return -1;
        if (n < 18) {
            if (n == 0) {
                return 0;
            }
            if (n == 6 || n == 8) {
                return 1;
            }
            if (n == 12 || n == 14 || n == 16) {
                return 2;
            }
            return -1;
        }
        return (n - 18) / 8 + 3;
    }
};
// 2.草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
// 每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64....
// 谁在自己的回合正好把草吃完谁赢，根据输入的n，返回谁赢
class Solution2
{
public:
    char CalculateWinner1(int n)
    {

        return f(n, 'A', 'B');
    }
    char f(int n, char curcompetitor, char nextcompetitor)
    {
        if (n == 0)
            return nextcompetitor;
        //当前选手选择吃多少草
        for (int i = 1; i <= n; i *= 4)
        {
            if (f(n - i, nextcompetitor, curcompetitor) == curcompetitor)
                return curcompetitor;
        }
        return nextcompetitor;
    }
    char CalculateWinner2(int n)
    {
        if (n % 5 == 0 || n % 5 == 2) {
            return 'B';
        }
        else {
            return 'A';
        }
    }
};

//3. 判断一个数字是否是若干数量(数量>1)的连续正整数的和
class Solution3
{
public:
    bool JudgeNumber1(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            int res = 0;
            //比较坑的一点：j必须小于等于，不能小于，特例：3
            for (int j = i; j <= n; j++)
            {
                if (res > n)
                    break;
                else if (res == n)
                    return true;
                else
                    res += j;
            }
        }
        return false;
    }
    bool JudgeNumber2(int num)
    {
        return (num & (num - 1)) != 0;
    }

};

// 4.可以用r、e、d三种字符拼接字符串，如果拼出来的字符串中
// 有且仅有1个长度>=2的回文子串，那么这个字符串定义为"好串"
// 返回长度为n的所有可能的字符串中，好串有多少个
// 结果对 1000000007 取模， 1 <= n <= 10^9
// 示例：
// n = 1, 输出0
// n = 2, 输出3
// n = 3, 输出18
class Solution4
{
public:
    int CalculateGoodString(int n)
    {

    }
};
