//
// P1540.cpp 
// Created by Hollin on 8/4/2020
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    int ans = 0;
    deque<int> q;
    for(int i = 0; i < N; i++){
        int now;
        cin >> now;
        bool found = false;
        for(int i = 0; i < q.size(); i++){
            if(q[i] == now){
                found = true;
            }
        }
        if(!found){
            ans += 1;
            if(q.size() == M){
                q.pop_front();
            }
            q.push_back(now);
        }
    }
    cout << ans << endl;
    return 0;
}