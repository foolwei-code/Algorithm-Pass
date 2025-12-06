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