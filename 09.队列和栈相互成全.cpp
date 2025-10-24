#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//1.用栈实现队列
//测试链接 : https://leetcode.cn/problems/implement-queue-using-stacks/
/*
两条规则：
1.stack1向stack2内倒数据的时候，stack2必须是空的
2.stack1向stack2内倒数据的时候，必须全部倒完
*/
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        peek();
        int top = stack2.top();
        stack2.pop();
        return top;
    }

    int peek() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(!stack2.empty())  //防止第一个操作就是empty
        return stack2.top();
        return -1;   //随机返回什么值都可以
    }

    bool empty() {
        peek();
        return stack2.empty();
    }
private:
    stack<int>stack1;
    stack<int>stack2;
};

//2.用队列实现栈
// 测试链接 : https://leetcode.cn/problems/implement-stack-using-queues/
class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        queue.push(x);
        for (int i = 0; i < queue.size() - 1; i++)
        {
            queue.push(queue.front());
            queue.pop();
        }
    }

    int pop() {
        int front = queue.front();
        queue.pop();
        return front;
    }

    int top() {
        return queue.front();
    }

    bool empty() {
        return queue.empty();
    }
private:
    queue<int>queue;
};

int main()
{

	return 0;
}