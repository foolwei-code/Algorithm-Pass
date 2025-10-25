#include<iostream>
#include<vector>
using namespace std;
//设计双端队列
//跟之前一样，我这里只提供数组的实现方式，链表的实现方式请自行学习
// 测试链接 : https://leetcode.cn/problems/design-circular-deque/
class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        deque.resize(k);
        size=l = r = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (size == capacity)
            return false;
        l = l == 0 ? capacity - 1 : l - 1;
        deque[l] = value;
        size++;
        return true;
    }
    bool insertLast(int value) {
        if (size == capacity)
            return false;
        deque[r] = value;
        r = r == capacity - 1 ? 0 : r + 1;
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0)
            return false;
        l = l == capacity - 1 ? 0 : l+1;
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0)
            return false;
        r = r == 0 ? capacity - 1 : r - 1;
        size--;
        return true;
    }

    int getFront() {
        if (size == 0)
            return -1;
        return deque[l];
    }

    int getRear() {
        if (size == 0)
            return -1;
        int pos = r == 0 ? capacity - 1 : r - 1;
        return deque[pos];
    }

      bool isEmpty() {
          if (size == 0)
              return true;
          return false;
    }

    bool isFull() {
        if (size == capacity)
            return true;
        return false;
    }
private:
    vector<int>deque;
    int l, r;
    int size, capacity;
};

int main()
{
	return 0;
}