//
// heapdijkstra.cpp 
// Created by Hollin on 7/27/2020
//
#include <bits/stdc++.h>
using namespace std;

struct cmp{
    operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    }
};

const int maxn = 5e2 + 1;
bool vis[maxn];
int dis[maxn];

vector<vector<int>> graph(maxn, vector<int>(maxn, 10000));

priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> heap;

void dijkstra(int v, int n){
    dis[v] = 0;
    heap.push({v, 0});
    while(!heap.empty()){
        pair<int, int> tp = heap.top(); heap.pop();
        int nv = tp.first;
        int w = tp.second;
        if(vis[nv]){
            continue;
        }
        vis[nv] = 1;
        cout << nv << endl;
        for(int j = 0; j < n; j++){
            if(!vis[j] && w + graph[nv][j] < dis[j]){
                dis[j] = graph[nv][j] + w;
                heap.push({j, dis[j]});
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    memset(dis, 10000, sizeof(int) * n);
    memset(vis, 0, sizeof(bool) * n);
    while(e-- > 0){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = w;
        graph[y][x] = w;
    }
    for(int i = 0; i < n; i++){
        graph[i][i] = 0;
    }
    dijkstra(0, n);
    for(int i = 0; i < n; i++){
        cout << dis[i] << " ";
    }
    return 0;
}