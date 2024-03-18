#include <bits/stdc++.h>
#include <icecream.hpp>
using namespace std;
class Solution {

    inline bool isTriangle(int a, int b, int c){
        return (a + b > c) && (a + c > b) && (b + c > a);
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 多少个三元组，其对应的木棒长度所组成的三角形是令人愉悦的
     * @param length int整型vector 木棒长度
     * @return int整型
     */
    int happyTriangle(vector<int>& nums) {
        // write code here

        int cnt = 0;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i<n; ++i){
            for(int j = i + 1; j+1 < n; ++j){
                int lk = j + 1, rk = n - 1, k = j;

                while(lk <= rk){
                    int mid = (lk + rk) / 2;
                    if(nums[mid] < nums[i] + nums[j]){
                        k = mid;
                        lk = mid + 1;
                    }else{
                        rk = mid - 1;
                    }
                }

                IC(i, j, k, cnt);

                auto fix_val = std::pow(nums[i], 2) + std::pow(nums[j], 2);
                if( fix_val < std::pow(nums[k], 2)){
                    for(int c = j + 1; c<=k; ++c){
                        if(fix_val == std::pow(nums[c], 2)) --cnt;
                    }
                }

                IC(fix_val, cnt);

                bool same_flag  = nums[i] == nums[j];
                if(same_flag && nums[j] <= nums[k]){
                    for(int c = j+1; c <=k; ++c){
                        IC(nums[c], nums[j]);

                        if(nums[j] == nums[c]) --cnt;
                    }
                }

                IC(same_flag, cnt);

                cnt += (k - j);

                IC(cnt);
                cout<<endl;

            }   
        }



        // method 2

        // for(int i = 0; i< n; ++i){
        //     auto lval = std::pow(nums[i], 2);

        //     for(int j = i+1;j < n; ++j){
        //         auto mval = std::pow(nums[j], 2);

        //         for(int k = j + 1; k < n;++k){
        //             auto rval = std::pow(nums[k], 2);
                    
        //             if(lval == mval && mval == rval){
        //                 continue;
        //             }

        //             if(lval + mval == rval){
        //                 continue;
        //             }

        //             // if(lval + mval < rval){
        //             //     auto inner_cnt = n - k;
        //             //     cnt += inner_cnt;

        //             //     break;
        //             // }

        //             if(isTriangle(nums[i], nums[j], nums[k])){
        //                 ++cnt;
        //             }





        //         }
        //     }
        // }


        // method 1


        // for(int i = 0; i< n; ++i){
        //     int val = nums[i];

        //     int lk = i+1, rk = n-1;

        //     while(lk < rk){
        //         if(nums[lk] == nums[rk] && nums[lk] == val){
        //             // ++lk;
        //             // --rk;
        //             break;
        //         }

        //         int sum_val = (std::pow(val, 2) + std::pow(nums[lk], 2));
        //         int lst_val = std::pow(nums[rk], 2);
        //         if(sum_val > lst_val){
        //             ++cnt;
                    
        //         }else if(sum_val == lst_val){
        //             // 直角三角形

        //         }else{
        //             ++cnt;

        //         }
        //     }
        // }

        return cnt;
    }
};


int main(){

    vector<int> nums ={6,6,6};


    Solution sol;

    IC(sol.happyTriangle(nums));




    return 0;
}




