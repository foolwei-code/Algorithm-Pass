#include<iostream>
using namespace std;
// 测试链接 : https://leetcode.cn/problems/partition-list/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //定义4个指针
        ListNode* smallhead = nullptr, * smalltail = nullptr;
        ListNode* bighead = nullptr, * bigtail = nullptr;
        if (head == nullptr || head->next == nullptr)
            return head;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                if (smallhead == nullptr)
                    smallhead = smalltail = head;
                else
                {
                    smalltail->next = head;
                    smalltail = smalltail->next;
                }
            }
            else
            {
                if (bighead == nullptr)
                    bighead = bigtail = head;
                else
                {
                    bigtail->next = head;
                    bigtail = bigtail->next;
                }
            }
            head = head->next;
        }
        if (bigtail != nullptr)
            bigtail->next = nullptr;
        if (smalltail != nullptr)
        {
            smalltail->next = bighead;
            return smallhead;
        }
        return bighead;
    }
};
int main()
{
	return 0;
}