#include<iostream>
#include<vector>
using namespace std;
//这里只提供用数组的方式实现栈和队列，对于链表的方式请自行学习
class Stack
{
private:
	vector<int>arr;
	int top;
public:
	Stack() :top(-1) {};
	//1.压入元素
	void push(int x)
	{
		arr.push_back(x);
		top++;
	}
	//2.获取栈顶元素
	int getTop()
	{
		return arr[top];
	}
	//3.弹出元素
	void pop()
	{
		if(!Isempty())
		arr.pop_back();
		top--;
	}
	//4.判断栈空
	bool Isempty()
	{
		if (arr.empty())
			return true;
		return false;
	}
	~Stack(){}
};
class Queue
{
private:
	vector<int>arr;
	int l, r;
public:
	//设置队列长度
	Queue(int length) :l(0), r(0)
	{
		arr.resize(length);
	}
	//元素进入队列
	void push(int x)
	{
		arr[r++] = x;
	}
	//元素出队
	void pop()
	{
		l++;
	}
	//获取队头
	int front()
	{
		return arr[l];
	}
	//判断队列是否为空
	bool Isempty()
	{
		if (l == r)
			return true;
		return false;
	}
	~Queue(){}
};
//上述代码省略了一些边界讨论，请根据情况自行补充

//设计循环队列
// 测试链接 : https://leetcode.cn/problems/design-circular-queue/
class MyCircularQueue {
public:
	MyCircularQueue(int k) {
		arr.resize(k);
		l = r = 0;
		size = 0;
		capacity = k;
	}

	bool enQueue(int value) {
		if (size == capacity)
			return false;
		arr[r] = value;
		r = (r == capacity - 1) ? 0 : r + 1;
		size++;
		return true;
	}
	bool deQueue() {
		if (size == 0)
			return false;
		l = (l == capacity - 1) ? 0 : l + 1;
		size--;
		return true;
	}

	int Front() {
		if (size == 0)
			return -1;
		return arr[l];
	}

	int Rear() {
		if (size == 0)
			return -1;
		return r == 0 ? arr[capacity - 1] : arr[r - 1];
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
	vector<int>arr;
	int l, r, size, capacity;
};
int main()
{
	
	return 0;
}