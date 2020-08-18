//
// BinaryAddition.cpp 
// Created by Hollin on 8/9/2020
//

#include <bits/stdc++.h>
using namespace std;

string addOne(string now){
    int carry = 1;
    for(int i = 0; i < now.size(); i++){
        now[i] += carry;
        carry = (now[i] - '0') / 2;
        now[i] = (now[i] - '0') % 2 + '0';
    }
    if(carry > 0){
        now += carry + '0';
    }
    return now;
}

string flip(string now, int i){
    now[i] = now[i] == '0' ? '1' : '0';
    return now;
}

bool same(string S, string T, int len){
    if(S == T){
        return true;
    }
    for(int i = 0; i < len; i++) {
        if (S[i] != T[i]) {
            return false;
        }
    }
    for(int i = len; i < S.size(); i++){
        if(S[i] == '1'){
            return false;
        }
    }
    //cout << S << " " << T << endl;
    return true;
}

int main(){
    int  n;
    cin >> n;
    while(n-- > 0){
        int len;
        cin >> len;
        string S, T;
        cin >> S >> T;
        int ans = 0;
        unordered_set<string> vis;
        queue<string> q;
        q.push(S);
        while(!q.empty()) {
            int size = q.size();
            bool found = false;
            while (size-- > 0) {
                string now = q.front(); q.pop();
                vis.insert(now);
                if (same(now, T, len)) {
                    found = true;
                    break;
                }
                for (int i = 0; i < now.size(); i++) {
                    string flipped = flip(now, i);
                    if (vis.find(flipped) != vis.end()) {
                        continue;
                    }
                    q.push(flipped);
                }
                string added = addOne(now);
                if (vis.find(added) != vis.end()) {
                    continue;
                }
                q.push(added);
            }
            if(found){
                break;
            }
            ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}