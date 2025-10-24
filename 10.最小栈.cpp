#include<iostream>
#include<stack>
using namespace std;
// 测试链接 : https://leetcode.cn/problems/min-stack/
class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stack1.push(val);
        if (!stack2.empty() && val > stack2.top())
            stack2.push(stack2.top());
        else
            stack2.push(val);
    }

    void pop() {
        stack1.pop();
        stack2.pop();
    }

    int top() {
        return stack1.top();
    }

    int getMin() {
        return stack2.top();
    }
private:
    stack<int>stack1;
    stack<int>stack2;
};
int main()
{
	return 0;
}