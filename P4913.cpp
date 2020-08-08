//
// P4913.cpp 
// Created by Hollin on 8/8/2020
//
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> tree(n + 1, {0, 0});
    for(int i = 1; i <= n; i++){
        cin >> tree[i].first >> tree[i].second;
    }
    queue<pair<int, int>> q;
    q.push(tree[1]);
    int ans = 0;
    while(!q.empty()){
        ans += 1;
        int size = q.size();
        while(size-- > 0){
            pair<int, int> now = q.front();q.pop();
            if(now.first == now.second){
                continue;
            }
            if(now.first != 0){
                q.push(tree[now.first]);
            }
            if(now.second != 0) {
                q.push(tree[now.second]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}