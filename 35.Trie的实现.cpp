//https://leetcode.cn/problems/implement-trie-ii-prefix-tree/
#include<iostream>
#include<vector>
#include <string>
#include <functional>
//1.用类实现Trie(不推荐)
class Trie1 {
private:
   struct TrieNode {
        int pass;
        int end;
        std::vector<TrieNode*> nexts;
        TrieNode() : pass(0), end(0), nexts(26, nullptr) {}
    };

    TrieNode* root;

public:
    Trie1() {
        root = new TrieNode();
    }

    ~Trie1() {
        // 清理内存，防止内存泄漏
        std::function<void(TrieNode*)> deleteNode = [&](TrieNode* node) {
            if (!node) return;
            for (auto child : node->nexts) {
                if (child) {
                    deleteNode(child);
                }
            }
            delete node;
            };
        deleteNode(root);
    }

    void insert(std::string word) {
        TrieNode* node = root;
        node->pass++;
        for (int i = 0; i < word.length(); i++) {
            int path = word[i] - 'a';
            if (!node->nexts[path]) {
                node->nexts[path] = new TrieNode();
            }
            node = node->nexts[path];
            node->pass++;
        }
        node->end++;
    }

    // 如果之前word插入过前缀树，那么此时删掉一次
    // 如果之前word没有插入过前缀树，那么什么也不做
    void erase(std::string word) {
        if (countWordsEqualTo(word) > 0) {
            TrieNode* node = root;
            node->pass--;
            for (int i = 0; i < word.length(); i++) {
                int path = word[i] - 'a';
                if (--node->nexts[path]->pass == 0) {
                    // 清理内存
                    std::function<void(TrieNode*)> deleteNode = [&](TrieNode* node) {
                        if (!node) return;
                        for (auto child : node->nexts) {
                            if (child) {
                                deleteNode(child);
                            }
                        }
                        delete node;
                        };
                    deleteNode(node->nexts[path]);
                    node->nexts[path] = nullptr;
                    return;
                }
                node = node->nexts[path];
            }
            node->end--;
        }
    }

    // 查询前缀树里，word单词出现了几次
    int countWordsEqualTo(std::string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int path = word[i] - 'a';
            if (!node->nexts[path]) {
                return 0;
            }
            node = node->nexts[path];
        }
        return node->end;
    }

    // 查询前缀树里，有多少单词以pre做前缀
    int countWordsStartingWith(std::string pre) {
        TrieNode* node = root;
        for (int i = 0; i < pre.length(); i++) {
            int path = pre[i] - 'a';
            if (!node->nexts[path]) {
                return 0;
            }
            node = node->nexts[path];
        }
        return node->pass;
    }
};
// 测试链接 : https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b
//用固定数组实现Tire(推荐)
const int N = 1e5 + 5;
std::vector<std::vector<int>>Trie(N, std::vector<int>(26));
std::vector<int>pass(N, 0), end(N, 0);
std::string s;
int m, operators,cnt;
void build()
{
    cnt = 1;
}
void insert(std::string&str)
{
    int cur = 1;
    pass[cur]++;
    for (int i = 0; i < str.size(); i++)
    {
        int path = str[i] - 'a';
        if (Trie[cur][path] == 0)
            Trie[cur][path] = ++cnt;
        cur = Trie[cur][path];
        pass[cur]++;
    }
    end[cur]++;
}
int search(std::string& str)
{
    int cur = 1;
    for (int i = 0; i < str.size(); i++)
    {
        int path = str[i] - 'a';
        if (Trie[cur][path] == 0)
            return 0;
        cur = Trie[cur][path];
    }
    return end[cur];
}
int prefixNumber(std::string& str)
{
    int cur = 1;
    for (int i = 0; i < str.size(); i++)
    {
        int path = str[i] - 'a';
        if (Trie[cur][path] == 0)
            return 0;
        cur = Trie[cur][path];
    }
    return pass[cur];
}
void deletestr(std::string& str)
{
    int cur = 1;
    pass[cur]--;
    if (search(str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            int path = str[i] - 'a';
            if (--pass[Trie[cur][path]] == 0)
                Trie[cur][path] = 0;
            cur = Trie[cur][path];
        }
        end[cur]--;
    }
}
void clear()
{
    for (auto& row : Trie)
        std::fill(row.begin(), row.end(), 0);
}
int main()
{
    std::cin >> m;
    build();
    while (m--)
    {
        std::cin >> operators >> s;
        if (operators == 1)
            insert(s);
        else if (operators == 2)
          deletestr(s);
        else if (operators== 3)
        {
            if (search(s))
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }
        else
        {
            std::cout << prefixNumber(s) << std::endl;
        }
    }
    clear();
}