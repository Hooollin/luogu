//
// P4387.cpp 
// Created by Hollin on 8/7/2020
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q-- > 0){
        int n;
        cin >> n;
        vector<int> pushed(n);
        vector<int> poped(n);
        for(int i = 0; i < n; i++){
            cin >> pushed[i];
        }
        for(int i = 0; i < n; i++){
            cin >> poped[i];
        }
        stack<int> s;
        int now = 0;
        for(int i = 0; i < n; i++){
            s.push(pushed[i]);
            while(s.top() == poped[now]){
                now += 1;
                s.pop();
                if(s.empty()){
                    break;
                }
            }
        }
        if(s.empty()){
            cout << "Yes" << endl;
        }else cout << "No" << endl;

    }
    return 0;
}