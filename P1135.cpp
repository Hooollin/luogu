//
// P1135.cpp 
// Created by Hollin on 7/29/2020
//
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e2 + 1;
int steps[maxn];
bool vis[maxn];
const int inf = 1e9 + 1;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    for(int i = 1; i <= N; i++){
        cin >> steps[i];
        vis[i] = false;
    }
    if(A == B){
        cout << 0 << endl;
        return 0;
    }

    int round = 0;
    queue<int> q;
    q.push(A);
    vis[A] = true;
    while(!q.empty()){
        int size = q.size();
        round += 1;
        while(size-- > 0){
            int u = q.front(); q.pop();
            int np = u + steps[u];
            if(np == B){
                vis[np] = true;
                break;
            }
            if(np > 0 && np <= N && steps[u] != 0 && !vis[np]){
                vis[np] = true;
                q.push(np);
            }
            np = u - steps[u];
            if(np == B){
                vis[np] = true;
                break;
            }
            if(np > 0 && np <= N && steps[u] != 0 && !vis[np]){
                vis[np] = true;
                q.push(np);
            }
        }
        if(vis[B]){
            break;
        }
    }
    if(vis[B]){
        cout << round << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;

}