#include<iostream>
using namespace std;
//practice1 : ��ӡint�����ݵĶ�����״̬
class Solution
{
public:
	//���Ϊ��λ���Ҳ�Ϊ��λ
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