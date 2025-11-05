#include<iostream>
using namespace std;
// Brian Kernighan算法
// 提取出二进制里最右侧的1
// 1.判断一个整数是不是2的幂
// 测试链接 : https://leetcode.cn/problems/power-of-two/
class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        if (n == lowbit(n))
            return true;
        return false;
    }
    int lowbit(int x)
    {
        return x & (-x);
    }
};
// 2.判断一个整数是不是3的幂
// 测试链接 : https://leetcode.cn/problems/power-of-three/
class Solution2 {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        return  1162261467 % n == 0;
    }
};
// 3.已知n是非负数
// 返回大于等于n的最小的2某次方
// 如果int范围内不存在这样的数，返回整数最小值
class Solution3
{
public:
    int near2power(int n)
    {
        if (n <= 0)
            return  1;
        n--;
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);
        return ++n;
    }
};
// 4.给你两个整数 left 和 right ，表示区间 [left, right]
// 返回此区间内所有数字 & 的结果
// 包含 left 、right 端点
// 测试链接 : https://leetcode.cn/problems/bitwise-and-of-numbers-range/
class Solution4 {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right)
        {
            right -= (right & -right);
        }
        return right;
    }
};
int main()
{
	return 0;
}