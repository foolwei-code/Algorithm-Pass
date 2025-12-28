#include<iostream>
#include<vector>
#include<string>
using  namespace std;
// 1.牛牛和他的朋友们约定了一套接头密匙系统，用于确认彼此身份
// 密匙由一组数字序列表示，两个密匙被认为是一致的，如果满足以下条件：
// 密匙 b 的长度不超过密匙 a 的长度。
// 对于任意 0 <= i < length(b)，有b[i+1] - b[i] == a[i+1] - a[i]
// 现在给定了m个密匙 b 的数组，以及n个密匙 a 的数组
// 请你返回一个长度为 m 的结果数组 ans，表示每个密匙b都有多少一致的密匙
// 数组 a 和数组 b 中的元素个数均不超过 10^5
// 1 <= m, n <= 1000
// 测试链接 : https://www.nowcoder.com/practice/c552d3b4dfda49ccb883a6371d9a6932
class Solution1 {
public:
    vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) {
        // write code here
        vector<int>ans;
        build();
        for (int i = 0; i < a.size(); i++)
        {
            string temp;
            for (int j = 0; j < a[i].size() - 1; j++)
            {
                temp += (to_string(a[i][j + 1] - a[i][j]));
                temp += "#";
            }
            insert(temp);
        }
        for (int i = 0; i < b.size(); i++)
        {
            string temp;
            for (int j = 0; j < b[i].size() - 1; j++)
            {
                temp += (to_string(b[i][j + 1] - b[i][j]));
                temp += "#";
            }
            ans.push_back(search(temp));
        }
        return ans;
    }
    void insert(string& s)
    {
        int cur = 1;
        pass[cur]++;
        for (int i = 0; i < s.size(); i++)
        {
            int path = routine(s[i]);
            if (Tree[cur][path] == 0)
                Tree[cur][path] = ++cnt;
            cur = Tree[cur][path];
            pass[cur]++;
        }
        end[cur]++;
    }
    int search(string& s)
    {
        int cur = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int path = routine(s[i]);
            if (Tree[cur][path] == 0)
                return 0;
            cur = Tree[cur][path];
        }
        return pass[cur];
    }
    int routine(char ch)
    {
        if (ch == '#')
            return 10;
        if (ch == '-')
            return 11;
        return ch - '0';
    }
    void build()
    {
        Tree.resize(N);
        for (int i = 0; i < N; i++)
            Tree[i].resize(11);
        cnt = 1;
        pass.resize(N);
        end.resize(N);
    }
private:
    const int N = 100000+5;
    int cnt;
    vector<vector<int>>Tree;
    vector<int>pass;
    vector<int>end;
};

// 2.数组中两个数的最大异或值
// 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0<=i<=j<=n
// 1 <= nums.length <= 2 * 10^5
// 0 <= nums[i] <= 2^31 - 1
// 测试链接 : https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
class Solution2 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxnum = numeric_limits<int>::min();
        for (auto p : nums)
            maxnum = max(p, maxnum);
        //算出最大元素的前导零的个数
        zero_number = 0;
        zero_number = getzero(maxnum);
        //将每个数插入到前缀树上
        build();
        for (auto p : nums)
            insert(p);
        //计算最大异或值
        int ans = 0;
        for (auto p : nums)
        {
            ans = max(ans, maxxro(p));
        }
        return ans;
    }
    int getzero(int maxnum)
    {
        int cnt = 0;
        while (maxnum != 0)
        {
            cnt++;
            maxnum >>= 1;
        }
        return 32 - cnt;
    }
    void build()
    {
        cnt = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 2; j++)
                Tree[i][j] = 0;
            pass[i] = 0;
            end[i] = 0;
        }
    }
    void insert(int num)
    {
        int cur = 1, start = 31 - zero_number;
        pass[cur]++;
        for (; start >= 0; start--)
        {
            int path = ((num >> start) & 1);
            if (Tree[cur][path] == 0)
                Tree[cur][path] = ++cnt;
            cur = Tree[cur][path];
            pass[cur]++;
        }
        end[cur]++;
    }
    int maxxro(int num)
    {

        int cur = 1, ans = 0;
        int start = 31 - zero_number;
        for (; start >= 0; start--)
        {
            int status = (num >> start) & 1;
            int want = status ^ 1;
            if (Tree[cur][want] == 0)
                want ^= 1;
            ans |= (status ^ want) << start;
            cur = Tree[cur][want];
        }
        return ans;
    }
private:
    static const int N = 3000001;
    static int Tree[N][2];
    static int pass[N];
    static  int end[N];
    int cnt;
    int zero_number;
};
int Solution2::Tree[N][2];
int Solution2::pass[N];
int Solution2::end[N];
