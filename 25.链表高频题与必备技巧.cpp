#include<iostream>
using namespace std;
// 1.返回两个无环链表相交的第一个节点
// 测试链接 : https://leetcode.cn/problems/intersection-of-two-linked-lists/
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
  class Solution1 {
  public:
      ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
          if (headA == nullptr || headB == nullptr)
              return  nullptr;
          ListNode* tempA = headA, * tempB = headB;
          int lenA = 0, lenB = 0;
          while (tempA != nullptr)
              lenA++, tempA = tempA->next;
          while (tempB != nullptr)
              lenB++, tempB = tempB->next;
          if (lenA < lenB)
              swap(headA, headB);
          int len = lenA >= lenB ? lenA - lenB : lenB - lenA;
          for (int i = 0; i < len; i++)
              headA = headA->next;
          while (headA != headB)
          {
              headA = headA->next;
              headB = headB->next;
          }
          return headA;
      }
  };
  // 2.每k个节点一组翻转链表
// 测试链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/
  class Solution2 {
  public:
      ListNode* reverseKGroup(ListNode* head, int k) {
          if (head == nullptr || head->next == nullptr)
              return head;
          ListNode* start = head, * end = nullptr;
          end = teamnum(head, k);
          if (end == nullptr)
              return head;
         //先处理第一批，因为涉及到换头
          myreverse(start,k);
          head = end;
          ListNode* lastteamend = start;
          while (lastteamend->next != nullptr)
          {
              start = lastteamend->next;
              end = teamnum(start, k);
              if (end == nullptr)
                  return head;
              myreverse(start, k);
              lastteamend->next = end;
              lastteamend = start;
          }
          return  head;
      }
      ListNode* teamnum(ListNode* s, int k)
      {
          while (--k && s != nullptr)
              s = s->next;
          return s;
      }
      void myreverse(ListNode* s,int k)
      {
          ListNode* pre = nullptr, *cur = s;
          for (int i = 0; i < k; i++)
          {
              ListNode* next = cur->next;
              cur->next = pre;
              pre = cur;
              cur = next;
          }
          s->next = cur;
      }
  };
  // 3.判断链表是否是回文结构
// 测试链接 : https://leetcode.cn/problems/palindrome-linked-list/
  class Solution3 {
  public:
      bool isPalindrome(ListNode* head) {
          //快慢指针法处理
          if (head == nullptr||head->next==nullptr)
              return true;
          ListNode* slow = head, * fast = head;
          while (fast->next != nullptr && fast->next->next != nullptr)
              slow = slow->next, fast = fast->next->next;
          //将slow后面的链表节点反转
          ListNode* pre = slow, * cur = slow->next;
          slow->next = nullptr;
          while (cur != nullptr)
          {
              ListNode* next = cur->next;
              cur->next = pre;
              pre = cur; cur = next;
          }
          //从两头向中间遍历
          while (head != nullptr)
          {
              if (head->val != pre->val)
                  return false;
              head = head->next;
              pre = pre->next;
          }
          return true;
      }
  };
  // 4.复制带随机指针的链表
  // 测试链接 : https://leetcode.cn/problems/copy-list-with-random-pointer/
  class Node {
  public:
      int val;
      Node* next;
      Node* random;

      Node(int _val) {
          val = _val;
          next = nullptr;
          random = nullptr;
      }
  };
  class Solution4 {
  public:
      Node* copyRandomList(Node* head) {
          if (head == nullptr)
              return head;
          Node* cur = head;
          //将每个链表节点的后面跟一个copy链表节点
          while (cur != nullptr)
          {
              Node* next = cur->next;
              Node* middle = new Node(cur->val);
              cur->next = middle;
              middle->next = next;
              cur = next;
          }
          Node* pre = head;
          Node* copyhead = nullptr;
          copyhead = cur = head->next;
          //先进行random指针的复制
          while (cur != nullptr)
          {
              cur->random = pre->random == nullptr ? nullptr : pre->random->next;
              pre = pre->next->next;
              cur = cur->next == nullptr ? nullptr : cur->next->next;
          }
          //将两个链表分开
          pre = head, cur = head->next;
          while (cur != nullptr)
          {
              pre->next = cur->next;
              cur->next = cur->next == nullptr ? nullptr : cur->next->next;
              pre = pre->next;
              cur = cur->next;
          }
          return copyhead;
      }
  };
  // 5.返回链表的第一个入环节点
// 测试链接 : https://leetcode.cn/problems/linked-list-cycle-ii/
  class Solution5 {
  public:
      ListNode* detectCycle(ListNode* head) {
          if (head == nullptr || head->next == nullptr)
              return nullptr;
          ListNode* fast = head, * slow = head;
          bool flag = false;
          ListNode* ans = nullptr;
          //快指针一次走两步，慢指针一次走一步
          while (fast->next != nullptr && fast->next->next != nullptr)
          {
              slow = slow->next;
              fast = fast->next->next;
              if (fast == slow)
              {
                  flag = true;
                  break;
              }
          }
          if (flag)
          {
              //快指针回到原点，接下来两个指针都一次走一步
              fast = head;
              while (fast != slow)
                  fast = fast->next, slow = slow->next;
              ans = fast;
          }
          return ans;
      }
  };
int main()
{
	return 0;
}