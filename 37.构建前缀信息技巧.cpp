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
int num, k;
vector<int>nums(100005);
unordered_map<int, int>map;
int ans;
int main()
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




