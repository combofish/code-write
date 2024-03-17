#include <iostream>
#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    int n;
    // cin>>n;
    n = 3;

    vector<long long> nums(n);

    // long long val_sum = 0;
    // for(int i = 0; i< n; ++i){
    //     cin>>nums[i];
    //     val_sum += nums[i];
    // }

    nums = {2, 1, 4};

    vector<int> idxs(n);
    for(int i = 0; i< n; ++i){
        idxs[i] = i;
    }

    std::sort(idxs.begin(), idxs.end(), [&nums](const int a, const int b){
        return nums[a] < nums[b];
    });

    IC(nums, idxs);

    auto sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());
    IC(sorted_nums);

    long long sum_val = 0;
    for(auto &num: nums){
        sum_val += num;
    }

    // int lk = 0, rk = sum_val - sorted_nums.front();
    int lk = 0, rk = sum_val;
    IC(sum_val, lk, rk);

    vector<long long> results(n);
    const int diff_cnt = n - 1;

    for(int i = 0; i< n; ++i){
        auto curr_num = sorted_nums[i];
        rk -= curr_num;

        auto lcnt = i - 0;
        auto rcnt = n - 1 - i;

        long long lval = lcnt*curr_num;
        long long rval = rcnt*curr_num;

        // long long need_to_add = (lval - lk) + ;
        long long ladd = (lval - lk);
        long long radd = (rk - rval);
        long long need_to_be_added = ladd + radd;

        // IC(lcnt, rcnt, lval, rval, curr_num, ladd, radd, need_to_be_added);

        
        results[i] = need_to_be_added;
        lk += curr_num;
        
    }
    IC(results);

    vector<long long> ans_vec(n);

    for(int i =0; i< n; ++i){

        ans_vec[idxs[i]] = results[i];

        // ans_vec.emplace_back(
        //     results[idxs[i]];
        // );
    }

    IC(ans_vec);

    // std::sort(results.begin(), results.end(), [idxs](const int a, const int b){
    //     return idxs
    // });



    for(int i = 0; i< n; ++i){
        long long diff_cnt = 0;
        long long cur_num = nums[i];
        for(auto &num: nums){
            diff_cnt += std::abs(num - cur_num);
        }

        cout<<diff_cnt<<endl;
    }

    // for(auto &num: nums){
    //     // long long cur_sum = num * n;

    //     for(i)


    // }


    return 0;
}
// 64 位输出请用 printf("%lld")