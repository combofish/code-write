/*
 * @Author: larry combofish@163.com
 * @Date: 2024-02-25 16:50:07
 * @LastEditors: larry combofish@163.com
 * @LastEditTime: 2024-02-27 10:32:32
 * @FilePath: /code-write/src/02-25/test_01.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
#include <icecream.hpp>
#include <queue>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;

        auto dummyNode = new Node(0);
        auto curr = dummyNode;
        auto node = head;

        unordered_map<Node *, Node *> ump;
        while (node != nullptr)
        {
            auto nNode = new Node(node->val);
            ump[node] = nNode;
            curr->next = nNode;
            node = node->next;
            curr = curr->next;
        }

        curr = dummyNode;
        node = head;
        while (node != nullptr)
        {
            if (node->random != nullptr)
            {
                curr->next->random = ump[node->random];
            }
            node = node->next;
            curr = curr->next;
        }

        curr = dummyNode->next;
        delete dummyNode;
        return curr;
    }
};

int main(int argc, char const *argv[])
{

    auto n7 = new Node(7);
    auto n13 = new Node(13);
    auto n11 = new Node(11);
    auto n10 = new Node(10);
    auto n1 = new Node(1);

    auto root = n7;
    n7->next = n13;
    n13->next = n11;
    n13->random = n7;
    n11->next = n10;
    n11->random = n1;
    n10->next = n1;
    n10->random = n11;
    n1->random = n7;

    Solution sol;

    auto ans = sol.copyRandomList(root);

    IC(ans->val);
    auto curr = root;
    while(curr){
        auto a = curr->val;
        auto b = curr->random ? curr->random->val : 0;

        IC(a, b);
        
        curr = curr->next;
    }

    while (root != nullptr)
    {
        auto tmp = root;
        root = root->next;
        delete tmp;
    }

    return 0;
}
