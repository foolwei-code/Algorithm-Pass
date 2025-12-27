#include<iostream>
#include<vector>
#include<string>
using  namespace std;
// 牛牛和他的朋友们约定了一套接头密匙系统，用于确认彼此身份
// 密匙由一组数字序列表示，两个密匙被认为是一致的，如果满足以下条件：
// 密匙 b 的长度不超过密匙 a 的长度。
// 对于任意 0 <= i < length(b)，有b[i+1] - b[i] == a[i+1] - a[i]
// 现在给定了m个密匙 b 的数组，以及n个密匙 a 的数组
// 请你返回一个长度为 m 的结果数组 ans，表示每个密匙b都有多少一致的密匙
// 数组 a 和数组 b 中的元素个数均不超过 10^5
// 1 <= m, n <= 1000
// 测试链接 : https://www.nowcoder.com/practice/c552d3b4dfda49ccb883a6371d9a6932
class Solution {
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
