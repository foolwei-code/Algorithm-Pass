#include<iostream>
using namespace std;
//practice1 : 打印int型数据的二进制状态
class Solution
{
public:
	//左侧为高位，右侧为低位
	void PrintBinary(int nums)
	{
		for (int i = 31; i >= 0; i--)
		{
			cout << (((nums>>i) & 1) == 1) ? 1 : 0;
		}
	}
};
int main()
{
	Solution p;
	int num;
	cin >> num;
	p.PrintBinary(num);
	return 0;
}