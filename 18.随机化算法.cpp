#include<iostream>
#include<vector>
#include<random>
using namespace std;
// 无序数组中第K大的元素
// 测试链接 : https://leetcode.cn/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findnum(nums, 0, n - 1, k);
    }
    int findnum(vector<int>& nums, int l, int r, int k)
    {
        
        int first = l, last = r, i = l;
        static default_random_engine e(time(0));
        uniform_int_distribution<int>u(l, r);
        int val = nums[u(e)];
        while (last >= i)
        {
            if (nums[i] < val)
                swap(nums[first++], nums[i++]);
            else if (nums[i] == val)
                i++;
            else
                swap(nums[i], nums[last--]);
        }
        if (nums.size()-k>=first&&nums.size()-k<=last)
            return val;
        else if (nums.size()-k<first)
            return findnum(nums, l, first - 1, k);
        else
            return findnum(nums, last + 1, r, k);
    }
};
int main()
{
	return 0;
}