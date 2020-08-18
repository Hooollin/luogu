//
// P3348.cpp 
// Created by Hollin on 8/15/2020
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int inf = 0x3f3f3f3f;
// 0 -> left 1 -> right
int tree[maxn][2];
int graph[maxn][maxn];
int dist[maxn];
bool vis[maxn];

int depth(int now){
    if(now == 0){
        return 0;
    }
    if(tree[now][0] == 0 && tree[now][1] == 0){
        return 1;
    }
    return 1 + max(depth(tree[now][0]), depth(tree[now][1]));
}

int width(){
    queue<int> q;
    bool vis[maxn];
    q.push(1);
    vis[1] = true;
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        ans = max(size, ans);
        while(size-- > 0){
            int now = q.front();q.pop();
            if(tree[now][0] != 0){
                q.push(tree[now][0]);
            }
            if(tree[now][1] != 0){
                q.push(tree[now][1]);
            }
        }
    }
    return ans;
}


int dijkstra(int from, int to, int n){
    if(from == to){
        return 0;
    }
    dist[from] = 0;
    for(int i = 1; i <= n; i++){
        int k = -1;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && ((k == -1) || dist[j] < dist[k])){
                k = j;
            }
        }
        vis[k] = true;
        for(int j = 1; j <= n; j++){
            if(dist[k] + graph[k][j] < dist[j]){
                dist[j] = dist[k] + graph[k][j];
            }
        }
   }
    return dist[to];
}


int main(){
    memset(tree, 0, sizeof(tree));
    memset(graph, inf, sizeof(graph));
    memset(dist, inf, sizeof(dist));
    memset(vis, false, sizeof(vis));
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int from, to;
        cin >> from >> to;
        if(tree[from][0] == 0){
            tree[from][0] = to;
        }else{
            tree[from][1] = to;
        }
        graph[from][to] = 1;
        graph[to][from] = 2;
        graph[from][from] = 0;
        graph[to][to] = 0;
    }
    int from, to;
    cin >> from >> to;
    cout << depth(1) << endl;
    cout << width() << endl;
    cout << dijkstra(from, to, n) << endl;
    return 0;
}