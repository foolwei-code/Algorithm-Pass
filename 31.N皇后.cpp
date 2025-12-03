#include<vector>
using namespace std;
// N皇后问题
// 测试链接 : https://leetcode.cn/problems/n-queens-ii/
//f1函数为普通版本
//f2函数为位运算版本
class Solution {
public:
    int totalNQueens(int n) {
        queen.resize(n,0);
        visit.resize(n,0);
        ans = 0;
        //f1(queen,0,visit);
        //return ans;
        if (n < 1)
            return 0;
        int limits = (1 << n) - 1;
        return f2(limits, 0, 0, 0);
    }
    void f1(vector<int>& queen,int k,vector<bool>&visit)
    {
        if (k == queen.size())
        {
            ans++;
            return;
        }
        for (int i = 0; i < queen.size(); i++)
        {
            if (visit[i])
                continue;
            bool flag = false;
            for (int j = 0; j < k; j++)
                if (abs(k - j) == abs(i - queen[j]))
                {
                    flag = true;
                    break;
                }
            if (flag)
                continue;
            queen[k] = i;
            visit[i] = 1;
            f1(queen, k + 1, visit);
            visit[i] = 0;
        }
    }
    //left表示从左上到右下的限制
    //right表示从右上到左下的限制
    int f2(int limits, int col, int left, int right)
    {
        if (limits == col)
            return 1;
        int ban = left | right | col;
        int candidate = limits & (~ban),ans=0;
        //此时candidate的1表示可以填入的，0表示不能填入的
        while (candidate)
        {
            int place = candidate & (-candidate);
            candidate ^= place;
            ans += f2(limits, col | place, (left | place) << 1, (right | place) >> 1);
        }
        return ans;
    }
    vector<int>queen;
    vector<bool>visit;
    int ans;
};
