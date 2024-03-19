/*
 * @Author: larry combofish@163.com
 * @Date: 2024-02-25 16:50:07
 * @LastEditors: larry combofish@163.com
 * @LastEditTime: 2024-02-27 11:05:13
 * @FilePath: /code-write/src/02-25/test_01.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
#include <icecream.hpp>
#include <queue>
#include "../combofish_utils.hpp"



using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int min_val = -1;

        stack<TreeNode*> st;
        auto curr = root;
        while(curr != nullptr || !st.empty()){
            if(curr != nullptr){
                st.emplace(curr);
                curr = curr->left;
            }else{
                curr = st.top(); st.pop();

                IC(curr->val);

                --k;
                if(k == 0) return curr->val;

                curr = curr->right;
                
                if(curr) IC(curr->val);

            }

            IC(curr == nullptr);
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{

    auto root = new TreeNode(1, nullptr, new TreeNode(2));

    Solution sol;

    IC(sol.kthSmallest(root, 2));

    treenode_tools::deleteTreeNode(root);


    return 0;
}
