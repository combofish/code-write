/*
 * @Author: larry combofish@163.com
 * @Date: 2024-02-25 16:50:07
 * @LastEditors: larry combofish@163.com
 * @LastEditTime: 2024-02-29 14:42:02
 * @FilePath: /code-write/src/02-25/test_01.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cctype>
#include <bits/stdc++.h>
#include <icecream.hpp>
#include <queue>
#include "../combofish_utils.hpp"

using namespace std;

void out_qu(queue<pair<int, bool>> qu)
{
    vector<pair<int, bool>> vec;
    while (!qu.empty())
    {
        vec.insert(vec.begin(), qu.front());
        qu.pop();
    }
    IC(vec);
}
void out_qu(queue<pair<int, int>> qu)
{
    vector<pair<int, int>> vec;
    while (!qu.empty())
    {
        vec.insert(vec.begin(), qu.front());
        qu.pop();
    }
    IC(vec);
}
class Solution
{
    inline bool comp(const string &s1, const string &s2)
    {
        int n = s1.size(), cnt = 0;
        for (int i = 0; i < n && cnt <= 1; ++i)
        {
            if (s1[i] != s2[i])
                ++cnt;
        }
        return cnt == 1;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();

        queue<pair<string, vector<bool>>> st;
        vector<bool> used(n, false);
        st.emplace(beginWord, used);

        int step = 0;
        while (!st.empty())
        {
            int sz = st.size();
            ++step;
            IC(sz, step);
            
            while (sz-- > 0)
            {
                auto curr = st.front();
                IC(curr);

                st.pop();
                for (int i = 0; i < n; ++i)
                {

                    if (!curr.second[i] && comp(curr.first, wordList[i]))
                    {

                        if (wordList[i] == endWord)
                            return step;
                        vector<bool> vis = curr.second;
                        vis[i] = true;

                        st.emplace(wordList[i], vis);
                    }
                }
            }
        }

        return 0;
    }
};
int main(int argc, char const *argv[])
{

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int ans = 5;

    IC(beginWord, endWord, wordList, ans);

    Solution sol;
    IC(sol.ladderLength(beginWord, endWord, wordList));

    return 0;
}
