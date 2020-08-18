//
// P1364.cpp 
// Created by Hollin on 8/10/2020
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int inf = 0x3f3f3f3f;
int graph[maxn][maxn];
int weight[maxn];

int main(){
    int n;
    cin >> n;
    memset(graph, 0x3f3f3f3f, sizeof graph);
    memset(weight, 0, sizeof weight);
    for(int i = 0; i < n; i++){
        graph[i][i] = 0;
        cin >> weight[i];
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        if(x == -1 && y == -1){
            continue;
        }
        if(x == -1){
            graph[i][y] = 1;
            graph[y][i] = 1;
        }else if(y == -1){
            graph[x][i] = 1;
            graph[i][x] = 1;
        }else{
            graph[i][y] = 1;
            graph[y][i] = 1;
            graph[x][i] = 1;
            graph[i][x] = 1;
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][k] +graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    int ans = 1e6;
    for(int i = 0; i < n; i++){
        int now = 0;
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            if(graph[i][j] < inf) now += graph[i][j] * weight[j];
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}