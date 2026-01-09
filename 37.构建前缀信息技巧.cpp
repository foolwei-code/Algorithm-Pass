#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
// 1.利用前缀和快速得到区域累加和
// 测试链接 : https://leetcode.cn/problems/range-sum-query-immutable/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        for (int i = 0; i < nums.size(); i++)
            numbers[i + 1] = numbers[i] + nums[i];
    }

    int sumRange(int left, int right) {
        return numbers[right+1] - numbers[left];
    }
    ~NumArray()
    {
        for (int i = 1; i <= size; i++)
            numbers[i] = 0;
        size = 0;
    }
private:
    int size;
    static vector<int>numbers;
};
vector<int>NumArray::numbers(10005);

// 2.返回无序数组中累加和为给定值的最长子数组长度
// 给定一个无序数组arr, 其中元素可正、可负、可0
// 给定一个整数aim
// 求arr所有子数组中累加和为aim的最长子数组长度
// 测试链接 : https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5
#if 0
int num, k;
vector<int>nums(100005);
unordered_map<int, int>map;
int ans;
int main1()
{
    cin >> num >> k;
    for (int i = 1; i <= num; i++)
        cin >> nums[i];
    int sum = 0;
    for (int i = 0; i <= num; i++)
    {
        sum += nums[i];
        if (map.count(sum - k))
            ans = max(ans, i - map[sum - k]);
        if (!map.count(sum))
            map[sum] = i;
    }
    cout << ans << endl;
    for (int i = 1; i <= num; i++)
        nums[i] = 0;
    map.clear();

}
#endif
// 3.返回无序数组中累加和为给定值的子数组个数
// 测试链接 : https://leetcode.cn/problems/subarray-sum-equals-k/
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        map.clear();
        int sum = 0,ans=0;
        map[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (map.count(sum - k))
                ans += map[sum - k];
            map[sum]++;
        }
        return ans;
    }
private:
    unordered_map<int, int>map;
};

// 4.返回无序数组中正数和负数个数相等的最长子数组长度
// 给定一个无序数组arr，其中元素可正、可负、可0
// 求arr所有子数组中正数与负数个数相等的最长子数组的长度
// 测试链接 : https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb
const int N = 1e5 + 5;
vector<int>nums(N);
int n,temp;
unordered_map<int, int>map;
int main()
{
    cin >> n;
    int sum = 0,ans=0;
    map.clear();
    map[sum] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        nums[i] = (temp > 0) ? 1 : (temp < 0 ? -1 : 0);
        sum += nums[i];
        if (map.count(sum))
            ans = max(ans, i - map[sum]);
        if (!map.count(sum))
            map[sum] = i;
    }
    cout << ans << endl;
}
// 5.表现良好的最长时间段
// 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数
// 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是 劳累的一天
// 所谓 表现良好的时间段 ，意味在这段时间内，「劳累的天数」是严格 大于 不劳累的天数
// 请你返回 表现良好时间段 的最大长度
// 测试链接 : https://leetcode.cn/problems/longest-well-performing-interval/
class Solution5 {
public:
    int longestWPI(vector<int>& hours) {
        map.clear();
        int sum = 0, ans = 0;
        //初始时将0设置成-1位置
        for (int i = 0; i < hours.size(); i++)
        {
            sum += (hours[i] > 8 ? 1 : -1);
            if (sum > 0)
                ans = max(ans, i + 1);
            else
            {
                //sum<=0
                /*
                精妙之处：我们只需要找到sum-1的最早出现位置即可
                假设sum=-3，只需要找到-4最早出现的位置，其前面不可能会有-5
                ，-6等，因为数组的特殊性，-5，-6一定是由前一位数转换而来的
                */
                if (map.count(sum - 1))
                    ans = max(ans, i - map[sum - 1]);
            }
            if (!map.count(sum))
                map[sum] = i;
        }
        return ans;
    }
private:
    unordered_map<int, int>map;
};

// 6.使数组和能被P整除
// 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空）
// 使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
// 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
// 子数组 定义为原数组中连续的一组元素。
// 测试链接 : https://leetcode.cn/problems/make-sum-divisible-by-p/
class Solution6 {
public:
    int minSubarray(vector<int>& nums, int p) {
        map.clear();
        map[0] = -1;
        int ans = numeric_limits<int>::max();
        int mod = 0;
        for (int i = 0; i < nums.size(); i++)
            mod = (mod + nums[i]) % p;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i]) % p;
            int temp = sum % p;
            map[temp] = i;
            if (temp >= mod)
            {
                if (map.count(temp - mod))
                    ans = min(ans, i - map[temp - mod]);
            }
            else
            {
                if (map.count(temp + p - mod))
                    ans = min(ans, i - map[temp + p - mod]);
            }
        }
        return (ans == nums.size() ? -1 : ans);
    }
private:
    unordered_map<int, int>map;
};
// 7.每个元音包含偶数次的最长子字符串
// 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度
// 每个元音字母，即 'a'，'e'，'i'，'o'，'u'
// 在子字符串中都恰好出现了偶数次。
// 测试链接 : https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/
class Solution7 {
public:
    int findTheLongestSubstring(string s) {
        int status = 0, ans = 0;
        vector<int>map(32,-2);
        map[0] = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int cur = f(s[i]);
            if (cur != -1)
            {
                status ^= 1 << cur;
            }
            if (map[status] != -2)
            {
                ans = max(ans, i - map[status]);
            }
            else
                map[status] = i;
        }
        return ans;
    }
    int f(char ch)
    {
        switch (ch) {
        case 'a': return 0;
        case 'e': return 1;
        case 'i': return 2;
        case 'o': return 3;
        case 'u': return 4;
        default: return -1;
        }
    }
};




