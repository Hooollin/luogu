//
// P3613.cpp 
// Created by Hollin on 7/28/2020
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(0));
    while(q-- > 0){
        int type;
        cin >> type;
        if(type == 1){
            int i, j, k;
            cin >> i >> j >> k;
            if(k == 0){
                for(int z = 0; z < v[i].size(); z++){
                    if(v[i][z].first == k){
                        v[i].erase(v[i].begin() + z);
                        z -= 1;
                    }
                }
            }else{
                v[i].push_back({j, k});
            }
        }else{
            int i, j;
            cin >> i >> j;
            for(int t = v[i].size(); t >= 0; t--){
                if(v[i][t].first == j){
                    cout << v[i][t].second << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

