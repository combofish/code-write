#include<icecream.hpp>
#include <bits/stdc++.h>
#include <deque>

using namespace std;
class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param str_input string字符串  
     * @return string字符串
     */
    string reverseMessage(string str_input) {
        // write code here
        if(str_input.empty()) return "";

        int lk = 0, rk = str_input.size()-1;
        while(lk <=rk && str_input[lk] == ' ') ++lk;
        while(lk<=rk && str_input[rk] == ' ') --rk;

        deque<string> dq;
        string str;

        while(lk <= rk){
            char c = str_input[lk];
            if(!str.empty() && c == ' '){
                dq.push_front(std::move(str));
                str.clear();
            }else if(c != ' '){
                str.push_back(c);
            }
            ++lk;
        }
        if(!str.empty()){
            dq.push_front(std::move(str));
        }

        string ans;
        while(!dq.empty()){
            ans += dq.front();
            dq.pop_front();
            if(!dq.empty()) ans += ' ';
        }
        return ans;
    }
};


int main(){

    Solution sol;
    string s = "the sky is blue";
    IC(s);
    IC(sol.reverseMessage(s));

    return 0;
}