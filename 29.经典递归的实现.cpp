#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
#include<algorithm>
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
int main()
{
	return 0;
}