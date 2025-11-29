#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
// 1.含有嵌套的表达式求值
// 力扣上本题为会员题，所以额外提供了牛客网的测试链接
// 如果在牛客网上提交，请将函数名从calculate改为solve
// 测试链接 : https://leetcode.cn/problems/basic-calculator-iii/
// 测试链接 : 
class Solution1
{
public:
	int solve(string s)
	{
		where = 0;
		return f(s, 0);
	}
	int f(string& s, int k)
	{
		int cur = 0;
		//准备两个栈，一个数字栈，一个符号栈
		stack<int>number;stack<char> operators;
		int i = k;
		while (s[i] != ')' && i < s.length())
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				cur = cur * 10 + (s[i++] - '0');
			}
			else if (s[i] == '(')
			{
				cur = f(s, i + 1);
				i = where + 1;
			}
			else
			{
				push(number, operators, cur, s[i++]);
				cur = 0;
			}
		}
		//将最后的字符加入栈中 
		push(number, operators, cur, '+');
		where = i;
		return compute(number, operators);
	}
	void push(stack<int>& number, stack<char>& operators, int cur, char oper)
	{
		if (number.empty())
		{
			number.push(cur);
			operators.push(oper);
		}
		else
		{
			if (operators.top() == '*'||operators.top()=='/')
			{
				int numtop = number.top();
				number.pop();
				char opertop = operators.top();
				operators.pop();
				if (opertop == '*')
					numtop *= cur;
				if (opertop == '/')
					numtop /= cur;
				number.push(numtop);
				operators.push(oper);
			}
			else
			{
				number.push(cur);
				operators.push(oper);
			}
		}
	}
	int compute(stack<int>& number, stack<char>& operators)
	{
		int ans = 0;
		operators.pop();
		while (!operators.empty())
		{
			int topnum = number.top();
			char topoper = operators.top();
			number.pop(), operators.pop();
			ans += (topoper == '+' ? topnum : -topnum);
		}
		ans += number.top();
		return  ans;
	}
private:
	int where;
};

