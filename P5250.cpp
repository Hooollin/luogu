//
// P5250.cpp 
// Created by Hollin on 8/18/2020
// 
#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> now;
    int n;
    cin >> n;
    while(n-- > 0){
        int type, m;
        cin >> type >> m;
        if(type == 1){
            if(now.find(m) != now.end()){
                cout << "Already Exist" << endl;
            }else{
                now.insert(m);
            }
        }else{
            if(now.size() == 0){
                cout << "Empty" << endl;
            }else{
                auto f = lower_bound(now.begin(), now.end(), m);
                if(f == now.end()) {
                    cout << *(--f) << endl;
                    now.erase(f);
                }else if(f == now.begin()){
                    cout << *f << endl;
                    now.erase(f);
                }else{
                    int h = *f;
                    int l = *(--f);
                    if(m - l <= h - m){
                        cout << l << endl;
                        now.erase(l);
                    }else{
                        cout << h << endl;
                        now.erase(h);
                    }
                }
            }
        }
    }
    return 0;
}