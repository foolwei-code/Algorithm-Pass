#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
using namespace std;
// 1.setAll功能的哈希表
// 测试链接 : https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
unordered_map<int, pair<int,int>>map;
int n, opt,x,y,Time;
int settime, setvalue; //时间戳技术
int main()
{
	cin >> n;
	while (n--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> x >> y;
			map[x] = { y,Time++ };//标记是time时间加入的
		}
		else if (opt == 2)
		{
			cin >> x;
			if (map.count(x))
			{
				if (map[x].second < settime)
					cout << setvalue << endl;
			}
			else
				cout << map[x].first << endl;
		}
		else
		{
			cin >> y;
			settime = Time++;
			setvalue = y;
		}
	}
	return 0;
}