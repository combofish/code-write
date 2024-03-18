#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <icecream.hpp>

using namespace std;

vector<int> get_item(const string &str){
    auto idx = str.find('(');
    auto num = str.substr(0, idx);
    auto cnt = str.substr(idx+1);
    cnt.pop_back();

    return {std::stoi(num), std::stoi(cnt)};
}

vector<vector<int>> split_cnt(const vector<string> &strs){
    vector<vector<int>> ans;

    for(auto &str: strs){
        auto tmp = get_item(str);
        ans.emplace_back(tmp);
    }

    return ans;
}
int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    string str;

    // std::getline(ans);, basic_string<CharT, Traits, Alloc> &str)
    // cin>>str;
    str = "[1(2),1(1),-1(3)]";

    str.pop_back();
    str = str.substr(1);
    cout<<str<<endl;

    string tmp;
    vector<string> strs;
    stringstream ss(str);

    while(std::getline(ss, tmp, ',')){
        strs.emplace_back(tmp);
    }
    // std::getline()

    for(auto &item: strs){
        cout<<item<<' ';
    }
    cout<<endl;

    auto recs = split_cnt(strs);
    IC(recs);

    vector<vector<int>> ans_nums;
    for(auto &item: recs){
        if(ans_nums.empty()){
            ans_nums.emplace_back(item);
        }else if(ans_nums.back().front() == item.front()){
            ans_nums.back().back() += item.back();
        }else{
            ans_nums.emplace_back(item);
        }
    }

    IC(ans_nums);


    string ans;
    ans += '[';

    int n_cnt = ans_nums.size();
    for(int i = 0; i< n_cnt; ++i){

        string cur_str="";

        cur_str += std::to_string(ans_nums[i].front());
        cur_str += '(';
        cur_str += std::to_string(ans_nums[i].back());
        cur_str += ')';
        
        if(i < n_cnt-1){
            cur_str +=',';
        }

        ans += cur_str;

    }






    ans +=']';

    cout<<ans<<endl;


    return 0;
}
// 64 位输出请用 printf("%lld")