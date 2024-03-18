/*
 * @Author: larry combofish@163.com
 * @Date: 2024-02-25 16:50:07
 * @LastEditors: larry combofish@163.com
 * @LastEditTime: 2024-02-29 12:00:05
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
    // inline pair<int, int> n2idx(int idx, const int n)
    // {
    //     int i = n - 1 - (idx - 1) / n;
    //     int j = (idx - 1) % n;

    //     if (i % 2 != 1)
    //     {
    //         j = n - j - 1;
    //     }

    //     return {i, j};
    // }
    inline pair<int, int> n2idx(int idx, const int n)
    {
        int i = (idx - 1) / n;
        int j = (idx - 1) % n;

        if (i % 2 == 1)
        {
            j = n - j - 1;
        }
        return {n - 1 - i, j};
    }

public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();

        queue<pair<int, bool>> qu; // curr, bool
        qu.emplace(1, 0);

        // int ans = INT_MAX;
        int step = 0;
        while (!qu.empty())
        {
            int sz = qu.size();
            ++step;
            IC(step);

            out_qu(qu);

            while (sz-- > 0)
            {
                auto point = qu.front();
                qu.pop();
                auto curr = point.first;
                for (int i = curr + 1; i <= std::min(curr + 6, n * n); ++i)
                {
                    int r, c, ni;
                    std::tie(r, c) = n2idx(i, n);

                    // IC(point, i, n, n2idx(i, n));

                    if (point.second && board[r][c] != -1)
                        continue; // 跳过

                    if (!point.second && board[r][c] != -1)
                    {
                        auto ni = board[r][c];
                        if (ni == n * n)
                            return step;

                        IC(point, i, n, n2idx(i, n), ni);

                        qu.emplace(ni, true);
                    }
                    else
                    {
                        if (i == n * n)
                            return step;

                        qu.emplace(i, point.second);
                    }
                    // if(ni == n*n) return step;
                }
            }
        }

        // return ans == INT_MAX ? -1: ans;
        return -1;
    }
};

class Solution2
{
    pair<int, int> id2rc(int id, int n)
    {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1)
        {
            c = n - 1 - c;
        }
        return {n - 1 - r, c};
    }

public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> vis(n * n + 1);
        queue<pair<int, int>> q;
        q.emplace(1, 0);
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            for (int i = 1; i <= 6; ++i)
            {
                int nxt = p.first + i;
                if (nxt > n * n)
                { // 超出边界
                    break;
                }
                auto rc = id2rc(nxt, n); // 得到下一步的行列
                if (board[rc.first][rc.second] > 0)
                { // 存在蛇或梯子
                    nxt = board[rc.first][rc.second];
                }

                IC(p, i, nxt);
                if (nxt == n * n)
                { // 到达终点
                    return p.second + 1;
                }
                if (!vis[nxt])
                {
                    vis[nxt] = true;
                    q.emplace(nxt, p.second + 1); // 扩展新状态
                }

                // IC(vis);
                out_qu(q);
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> board =
        {{1, 1, -1}, {1, 1, 1}, {-1, 1, 1}};
    int ans = -1;

    board = {{-1, 42, 12, -1, 1, -1, -1},
             {-1, -1, 5, -1, -1, 46, 44},
             {18, 22, 6, 39, -1, -1, -1},
             {-1, -1, 40, -1, -1, -1, 37},
             {49, 38, 24, -1, 14, 29, -1},
             {-1, -1, 6, -1, -1, -1, 20},
             {-1, -1, 12, 10, -1, 5, 26}};
    ans = 2;

    IC(board, ans);

    Solution solution;
    IC(solution.snakesAndLadders(board));

    Solution2 solution2;
    IC(solution2.snakesAndLadders(board));

    return 0;
}
