#include <iostream>
#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

int get_sum(vector<vector<int>> &nums, int il, int jl, int ik, int jk){
    IC(il, ik, jl, jk);

    int cut_val = 0;

    // cout<< " [" <<endl<<endl;
    for(int i = il; i< ik; ++i){

        // cout<< "("<< jk <<','<<jl<<")"<<endl;
        cut_val += (nums[i][jk] - nums[i][jl]);
        // cout<< cut_val<< ",";
    }

    // cout<<endl<<endl;

    // cout<<endl;

    return cut_val;
}
int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    int n;
    // cin >> n;
    n = 4;
    cout << n << endl;

    vector<string> strs(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> strs[i];
    // }

    strs = {"1010",
        "0101",
        "1100",
        "0011"
    };

    IC(n, strs);

    vector<vector<int>> boards(n, vector<int>(n));
    // for(auto &str: strs){
    for (int i = 0; i < n; ++i) {
        // cout<<str<<endl;
        auto str = strs[i];

        // for(int j)
        for (int j = 0; j < n; ++j) {
            boards[i][j] = (str[j] - '0');
        }
    }

    IC(boards);

    vector<vector<int>> sums(n, vector<int>(n + 1, 0));
    // for(int i = 0; i< n; ++i){
    //     for(int j = 0; j< n; ++j){
    //         // sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] + sums[i][j] +boards[i][j];
    //         if()

    //     }
    // }


    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sums[i][j] = sums[i][j - 1] + boards[i][j - 1];
        }
    }

    IC(sums);

    // -----

    for (int k = 1; k <= n; ++k) {
        if (k == 1) {
            cout << 0 << endl;
            continue;
        }

        if(k%2 == 1) {
            cout<< 0<<endl;
            continue;
        }

        int area = k * k / 2;
        int cur_cnt = 0;
        
        cout << "area = " << area << endl;

        for (int i = 0 ; i + k <= n; ++i) {
            for (int j = 0; j + k <= n; ++j) {
                // cout << i << ' ' << j  << ",";
                // cout << i + k << ' ' << j + k << ", ------";

                // cout<<tot[i][j] << ','<<tot[i+k][j+k]<<" --";

                // auto diff = tot[i + k][j + k] - tot[i][j];
                // cout << diff << endl;
                // cout<<endl;

                auto curr_sum = get_sum( sums, i, j, i + k, j + k);

                // cout<< " [] ="<< curr_sum<<endl;
                IC(curr_sum);
                if(curr_sum == area) ++cur_cnt;
            }
        }

        // cout<< cur_cnt<<endl;
        IC(area, cur_cnt);
        // break;
    }







    // vector<vector<int>> tot(n + 1, vector<int>(n + 1, 0));
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         // sums[i][j] = sums[i][j - 1] + boards[i - 1][j - 1];
    //         if (i == 1 ) tot[i][j] = sums[i][j];
    //         else {
    //             tot[i][j] = tot[i - 1][j] + sums[i][j];
    //         }

    //     }
    // }






    // vector<vector<int>> board(n, vector<int>(n, 0));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cin >> board[i][j];
    //     }
    // }
    // cout<< "nn"<<endl;

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << boards[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         cout << sums[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << " -------" << endl;

    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         cout << tot[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;


}
// 64 位输出请用 printf("%lld")