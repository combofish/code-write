#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

int main(){

    cout<<"hello world"<<endl;

    int n = 5;
    
    string name;
    int tmp;
    cin>>name>>tmp;

    // vector<string> strs(n);
    // for(int i = 0; i< n; ++i){
    //     cin>>name;
    //     strs[i] = name;
    // }

    // IC(strs);

    string strline;
    std::getline(cin, strline);
    IC(strline);
    
    std::getline(cin, strline);
    IC(strline);


    return 0;
}

/**
 
uuu 5
ab cd ef gh ij
*/