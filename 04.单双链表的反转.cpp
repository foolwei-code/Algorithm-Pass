#include<iostream>
using namespace std;
// https://leetcode.cn/problems/reverse-linked-list/
//1.单链表的反转
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* pre = head; ListNode* now = head->next;
        head->next = nullptr;  //切记：不要忘了将头节点的指针指向空
        while (now != nullptr)
        {
            ListNode* temp = now->next;
            now->next = pre;
            pre = now;
            now = temp;
        }
        return pre;
    }
};
//双链表的反转
struct DoubleListNode {
    int val;
    DoubleListNode* pre;
    DoubleListNode* next;
    DoubleListNode() : val(0), pre(nullptr),next(nullptr) {}
    DoubleListNode(int x) : val(x), pre(nullptr),next(nullptr) {}
    DoubleListNode(int x, DoubleListNode*pre,DoubleListNode* next) : val(x), pre(pre),next(next) {}
};
class Solution2
{
public:
    DoubleListNode* reverseDoubleList(DoubleListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        DoubleListNode* pre = head; DoubleListNode* now = head->next;
        while (now != nullptr)
        {
            pre->next = pre->pre;
            pre->pre = now;
            pre = now;
            now = now->next;
        }
        pre->next = pre->pre;
        pre->pre = now;
       
        return pre;
    }
};
int main()
{

	return 0;
}