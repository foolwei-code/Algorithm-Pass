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
int main()
{
	return 0;
}