#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 位图的实现
// Bitset(int size)
// void add(int num)
// void remove(int num)
// void reverse(int num)
// bool contains(int num)
class Bitset1
{
public:
	Bitset1(int size)
	{
		//存储0-size-1的数
		bitset.resize((size+31)/32);
	}
	void add(int num)
	{
		int pos1 = num / 32;//num在第几个int上
		int pos2 = num % 32;//num在该int的哪一位上
		bitset[pos1] |= 1 << pos2;
	}
	void remove(int num)
	{
		int pos1 = num / 32;
		int pos2 = num % 32;
		bitset[pos1] &=(~(1 << pos2));
	}
	void reverse(int num)
	{
		int pos1 = num / 32;
		int pos2 = num % 32;
		bitset[pos1] ^=(1 << pos2);
	}
	bool contains(int num)
	{
		int pos1 = num / 32;
		int pos2 = num % 32;
		return (bitset[pos1] & (1 << pos2));
	}
private:
	vector<int>bitset;
};
//测试链接：https://leetcode.cn/problems/design-bitset/submissions/676576064/
class Bitset2 {
public:
	Bitset2(int size) {
		bitset.resize((size + 31) / 32);
		onenum = 0;
		zeronum = size;
		bit_size = size;
		reverse = false;
	}

	void fix(int idx) {
		int pos1 = idx / 32;//num在第几个int上
		int pos2 = idx % 32;//num在该int的哪一位上
		if (!reverse)
		{
			if ((bitset[pos1] & (1 << pos2)) == 0)
			{
				bitset[pos1] |= 1 << pos2;
				onenum++, zeronum--;
			}

		}
		else
		{
			if ((bitset[pos1] & (1 << pos2)) != 0)
			{
				bitset[pos1] ^= 1 << pos2;
				onenum++, zeronum--;
			}
		}
	}

	void unfix(int idx) {
		int pos1 = idx / 32;//num在第几个int上
		int pos2 = idx % 32;//num在该int的哪一位上
		if (!reverse)
		{
			if ((bitset[pos1] & (1 << pos2)) != 0)
			{
				bitset[pos1] ^= 1 << pos2;
				onenum--, zeronum++;
			}

		}
		else
		{
			if ((bitset[pos1] & (1 << pos2)) == 0)
			{
				bitset[pos1] |= 1 << pos2;
				onenum--, zeronum++;
			}
		}
	}

	void flip() {
		swap(zeronum,onenum);
		reverse = !reverse;
	}

	bool all() {
		return onenum == bit_size;
	}

	bool one() {
		return  onenum;
	}

	int count() {
		return onenum;
	}

	string toString() {
		string ans;
		for (int i = 0, k = 0, number, status; i < bit_size; k++) {
			number = bitset[k];
			for (int j = 0; j < 32 && i < bit_size; j++, i++) {
				status = (number >> j) & 1;
				status ^= reverse ? 1 : 0;
				ans+=to_string(status);
			}
		}
		return ans;
	}
private:
	vector<int>bitset;
	int bit_size;
	int onenum;
	int zeronum;
	bool reverse;
};

int main()
{

	return 0;
}