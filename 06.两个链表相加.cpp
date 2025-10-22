#include<iostream>
using namespace std;
// 测试链接：https://leetcode.cn/problems/add-two-numbers/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;// 表示进位
        //先处理一下第一位的状态
        ListNode* head = new ListNode();
        head->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val) / 10;
        ListNode* cur = head;
        l1 = l1->next, l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr)
        {
            ListNode* temp = new ListNode();
            int num = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val);
            temp->val = (num + carry) % 10;
            carry = (num + carry) / 10;
            cur->next = temp;
            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;
            cur = cur->next;
        }
        if (carry)
        {
            ListNode* temp = new ListNode(carry);
            cur->next = temp;
        }
        return head;
    }
};
int main()
{
	return 0;
}