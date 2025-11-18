#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<random>
#include<ctime>
using namespace std;
// 1.setAll功能的哈希表
// 测试链接 : https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
unordered_map<int, pair<int,int>>map;
int n, opt,x,y,Time;
int settime, setvalue; //时间戳技术
//2.实现LRU结构
// 测试链接 : https://leetcode.cn/problems/lru-cache/
class LRUCache {
private:
    struct ListNode {
        int key;
        int value;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, ListNode*> map;
    ListNode* head;
    ListNode* tail;
    int capacity;
    int size;

    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToTail(ListNode* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    void moveToTail(ListNode* node) {
        removeNode(node);
        addToTail(node);
    }

public:
    LRUCache(int cap) : capacity(cap), size(0) {
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        ListNode* node = map[key];
        moveToTail(node);
        return node->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            ListNode* node = map[key];
            node->value = value;
            moveToTail(node);
        }
        else {
            if (size == capacity) {
                ListNode* toDelete = head->next;
                removeNode(toDelete);
                map.erase(toDelete->key);
                delete toDelete;
                size--;
            }
            ListNode* newNode = new ListNode(key, value);
            addToTail(newNode);
            map[key] = newNode;
            size++;
        }
    }
};
//3. 插入、删除和获取随机元素O(1)时间的结构
// 测试链接 : https://leetcode.cn/problems/insert-delete-getrandom-o1/
class RandomizedSet {
public:
    RandomizedSet() {
        size = 0;
    }

    bool insert(int val) {
        if (map.count(val))
            return false;
        arr.push_back(val);
        map[val] = size++;
        return true;
    }

    bool remove(int val) {
        if (map.count(val))
        {
            int index = map[val];
            swap(arr[index], arr[--size]);
            arr.pop_back();
            map[arr[index]] = index;
            map.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        static default_random_engine e(time(0));
        uniform_int_distribution<int>u(0, size - 1);
        return arr[u(e)];
    }
private:
    vector<int>arr;
    unordered_map<int, int>map;
    int size;
};


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