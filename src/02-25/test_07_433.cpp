/*
 * @Author: larry combofish@163.com
 * @Date: 2024-02-25 16:50:07
 * @LastEditors: larry combofish@163.com
 * @LastEditTime: 2024-02-29 17:03:55
 * @FilePath: /code-write/src/02-25/test_01.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cctype>
#include <bits/stdc++.h>
#include <icecream.hpp>
#include <queue>
#include "../combofish_utils.hpp"

using namespace std;
// class Solution {
//     unordered_map<string, int> ump;
//     vector<vector<int>> edges;
//     int nodeNum;
//     void addWord(const string &word){
//         if(!ump.count(word)){
//             ump[word] = nodeNum;
//             ++nodeNum;
//             edges.emplace_back();
//         }
//     }

//     void addEdge(string &word){
//         if(ump.count(word)) return;
//         // ()
//         addWord(word);
//         auto idx = ump[word];

//         for(char &c: word){
//             char tmp = c;
//             c = '*';
//             addWord(word);
//             auto idx2 = ump[word];
//             edges[idx].push_back(idx2);
//             edges[idx2].push_back(idx);
//             c = tmp;
//         }
//     }

// public:
//     int minMutation(string startGene, string endGene, vector<string>& bank) {
//         nodeNum = 0;
//         for(auto &word: bank) addEdge(word);

//         addEdge(startGene);
//         if(!ump.count(endGene)) return -1;

//         vector<int> vis(nodeNum, -1);
//         auto idx1 = ump[startGene], idx2 = ump[endGene];
//         vis[idx1] = 0;

//         IC(ump, vis, idx1, idx2, edges);

//         queue<int> qu;
//         qu.emplace(idx1);
//         while(!qu.empty()){
//             auto x = qu.front(); qu.pop();
//             if(x == idx2) return vis[idx2] / 2 + 1;

//             IC(x, edges[x]);

//             for(auto &it: edges[x]){
//                 if(vis[it] == -1){
//                     vis[it] = vis[x] + 1;
//                     qu.emplace(it);
//                 }
//             }

//             // IC(vis, qu.size(), ump);
//             out_qu(qu);
//         }

//         IC(ump[bank.back()]);

//         return -1;
//     }
// };

class Solution
{
    int nodeNum;
    unordered_map<string, int> ump;
    vector<vector<int>> edges;

    void addWord(const string &word)
    {
        if (!ump.count(word))
        {
            ump[word] = nodeNum++;
            edges.emplace_back();
        }
    }

    void addEdge(string &word)
    {
        if (ump.count(word))
            return;
        addWord(word);
        auto idx = ump[word];
        for (auto &c : word)
        {
            auto tmp = c;
            c = '*';
            addWord(word);
            auto nidx = ump[word];
            edges[idx].emplace_back(nidx);
            edges[nidx].emplace_back(idx);
            c = tmp;
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        nodeNum = 0;
        for (auto &word : wordList)
            addEdge(word);
        addEdge(beginWord);
        if (!ump.count(endWord))
            return 0;

        auto idx1 = ump[beginWord], idx2 = ump[endWord];
        queue<int> qu;
        qu.emplace(idx1);
        vector<int> vis(nodeNum, -1);
        vis[idx1] = 0;

        IC(ump, edges);
        out_qu(qu);

        while (!qu.empty())
        {
            auto x = qu.front();
            qu.pop();
            if (x == idx2)
                return vis[idx2] /2 + 1;

            IC(edges[x]);

            for (auto &it : edges[x])
            {
                if (vis[it] == -1)
                {
                    vis[it] = vis[x] + 1;
                    qu.emplace(it);

                    IC(x, it);
                    out_qu(qu);
                }
            }
            out_qu(qu);
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{

    string beginWord = "AACCGGTT";
    string endWord = "AACCGGTA";

    // vector<string> wordList = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    vector<string> wordList = {"AACCGGTA"};
    int ans = 2;

    IC(beginWord, endWord, wordList, ans);

    Solution sol;
    IC(sol.ladderLength(beginWord, endWord, wordList));

    return 0;
}
