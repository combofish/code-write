#include <icecream.hpp>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mat_mul(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int m = A.size(), n = A.front().size(), t = B.front().size();
    vector<vector<int>> ans(m, vector<int>(t));

    int val;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < t; ++j)
        {
            val = 0;

            for (int k = 0; k < n; ++k)
            {
                val += A[i][k] * B[k][j];
            }
            ans[i][j] = val;
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> A = {{1, 0, 0}, {-1, 0, 3}};
    vector<vector<int>> B = {
        {7, 0, 0},
        {0, 0, 0},
        {0, 0, 1}};

    vector<vector<int>> gt = {{{7, 0, 0},
                               {-7, 0, 3}}};
    IC(A, B, gt);

    auto ans = mat_mul(A, B);
    IC(ans);

    return 0;
}