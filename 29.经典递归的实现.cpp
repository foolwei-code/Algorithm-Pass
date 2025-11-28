#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
// 1.字符串的全部子序列
// 子序列本身是可以有重复的，只是这个题目要求去重
// 测试链接 : https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a
class Solution1 {
public:
    vector<string> generatePermutation(string s) {
        // write code here
        unordered_set<string>path;
        vector<string>ans;
        string substring;
        f(s, ans, path,0,substring);
        return ans;
    }
    void f(string& s, vector<string>& ans, unordered_set<string>& set,int i,string&substring)
    {
        if (i == s.size())
        {
            if (!set.count(substring))
            {
                set.insert(substring);
                ans.push_back(substring);
            }
            return;
        }
        substring.push_back(s[i]);
        f(s, ans, set, i+1, substring);
        substring.pop_back();
        f(s, ans, set, i + 1, substring);

    }
};
// 2.给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的组合
// 答案 不能 包含重复的组合。返回的答案中，组合可以按 任意顺序 排列
// 注意其实要求返回的不是子集，因为子集一定是不包含相同元素的，要返回的其实是不重复的组合
// 比如输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 测试链接 : https://leetcode.cn/problems/subsets-ii/
class Solution2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        //按照第一个元素的多少来进行划分
        vector<int>path;
        f(0, path, ans, nums);
        return ans;
    }
    void f(int i, vector<int>&path, vector<vector<int>>& ans, vector<int>& nums)
    {
        if (i == nums.size())
        {
            ans.push_back(path);
            return;
        }
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i])
            j++;
        for (int cnt = 0; cnt <= j - i; cnt++)
        {
            for (int k = 0; k < cnt; k++)
            {
                path.push_back(nums[i]);
            }
            f(j, path, ans, nums);
            //恢复现场
            for (int k = 0; k < cnt; k++)
                path.pop_back();
        }
    }
};
// 3.没有重复项数字的全排列
// 测试链接 : https://leetcode.cn/problems/permutations/
class Solution3 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0, nums, ans);
        return ans;
    }
    void f(int i, vector<int>& nums, vector<vector<int>>& ans)
    {
        if (i == nums.size())
            ans.push_back(nums);
        for (int k = i; k < nums.size(); k++)
        {
            swap(nums[i], nums[k]);
            f(i + 1, nums,ans);
            //恢复现场
            swap(nums[i], nums[k]);
        }
    }
};
// 4.有重复项数组的去重全排列
// 测试链接 : https://leetcode.cn/problems/permutations-ii/
class Solution4 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0, nums, ans);
        return  ans;
    }
    void f(int i, vector<int>& nums, vector<vector<int>>& ans)
    {
        if (i == nums.size())
            ans.push_back(nums);
        unordered_set<int>set;
        for (int k = i; k < nums.size(); k++)
        {
            if (set.count(nums[k]))
                continue;
            set.insert(nums[k]);
            swap(nums[i], nums[k]);
            f(i + 1, nums, ans);
            swap(nums[i], nums[k]);
        }
    }
};
//5.用递归实现逆序栈
class Solution5
{
public:
    void reversestack(stack<int>& stack)
    {
        if (stack.empty())
            return ;
        int num = bottomout(stack);
        reversestack(stack);
        stack.push(num);
    }
    int bottomout(stack<int>& stack)
    {
        int ans = stack.top();
        stack.pop();
        if (stack.empty())
            return ans;
        int last = bottomout(stack);
            stack.push(ans);
            return last;
        
    }
};
//6.用递归函数排序栈
// 栈只提供push、pop、isEmpty三个方法
// 请完成无序栈的排序，要求排完序之后，从栈顶到栈底从小到大
// 只能使用栈提供的push、pop、isEmpty三个方法、以及递归函数
// 除此之外不能使用任何的容器，数组也不行
// 就是排序过程中只能用：
// 1) 栈提供的push、pop、isEmpty三个方法
// 2) 递归函数，并且返回值最多为单个整数
class Solution6
{
public:
    void sortstack(stack<int>& stack)
    {
        int depth = deep(stack);
        while (depth > 0)
        {
            int maxnumber = maxnum(stack, depth);
            int count = times(stack, depth, maxnumber);
            down(stack, depth, maxnumber, count);
            depth -= count;
        }
    }
    // 返回栈的深度
    // 不改变栈的数据状况
    int deep(stack<int>& stack)
    {
        if (stack.empty())
            return 0;
        int top = stack.top();
        stack.pop();
        int depth = deep(stack) + 1;
        stack.push(top);
        return depth;
    }
    // 从栈当前的顶部开始，往下数deep层
     // 返回这deep层里的最大值
    int maxnum(stack<int>& stack, int depth)
    {
        if (depth == 0)
            return numeric_limits<int>::min();
        int top = stack.top();
        stack.pop();
        int res = max(top, maxnum(stack,depth-1));
        stack.push(top);
         return res;
    }
    // 从栈当前的顶部开始，往下数deep层，已知最大值是max了
    // 返回，max出现了几次，不改变栈的数据状况
    int times(stack<int>& stack, int depth, int maxnum)
    {
        if (depth == 0)
            return 0;
        int top = stack.top();
        stack.pop();
        int resttimes = times(stack, depth - 1, maxnum);
        stack.push(top);
        return top == maxnum ? resttimes + 1 : resttimes;
    }
    // 从栈当前的顶部开始，往下数deep层，已知最大值是max，出现了k次
    // 请把这k个最大值沉底，剩下的数据状况不变
    void down(stack<int>& stack, int depth, int maxnum, int times)
    {
        if (depth == 0)
        {
            for (int i = 0; i < times; i++)
                stack.push(maxnum);
            return;
        }
        int top = stack.top();
        stack.pop();
        down(stack, depth-1, maxnum, times);
        if (top != maxnum)
            stack.push(top);
    }
    void checkright(stack<int>& stack)
    {
        vector<int>temp;
        while (!stack.empty())
        {
            temp.push_back(stack.top());
            stack.pop();
        }
        sort(temp.begin(), temp.end());
        for (int i = temp.size() - 1; i >= 0; i--)
            stack.push(temp[i]);
    }
};
//7.汉诺塔问题
class Solution7
{
public:
    void printHnoi(int n)
    {
        f('A', 'B', 'C', n);
    }
    void f(char start, char middle, char end,int n)
    {
        if (n == 0)
            return;
        //1.将n-1个盘子借助end移动到 middle
        f(start, end, middle, n - 1);
        //2.将最后一个盘子移动到end
        cout << start << "->" << end << endl;
        //3.将n-1个盘子借助start移动到end
        f(middle, start, end, n - 1);
    }
};
int main()
{
	return 0;
}