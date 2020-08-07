//
// P1433.cpp
// Created by Hollin on 7/30/2020
//
#include <bits/stdc++.h>
using namespace std;
const double inf = 1e10;
const int maxn = 16;
double f[maxn][1 << maxn];
vector<pair<double, double>> ps(maxn);

double dis(int x, int y){
    return sqrt(pow(ps[y].first - ps[x].first, 2) + pow(ps[y].second - ps[x].second, 2));
}

int main(){
    int N;
    cin >> N;
    ps[0] = {0, 0};
    for(int i = 1; i <= N; i++){
        pair<double, double> p;
        cin >> p.first >> p.second;
        ps[i] = p;
    }
    memset(f, 127, sizeof(f));
    for(int s = 1; s < (1 << N); s++){
        for(int i = 1; i <= N; i++){
            // 状态中没有这个点
            if((s & (1 << (i - 1))) == 0){
                continue;
            }
            // 集合中只有这一个点
            if(s == (1 << (i - 1))){
                f[i][s] = 0;
                continue;
            }
            for(int j = 1; j <= N; j++){
                if(((s & (1 << (j - 1)))) == 0 || i == j){
                    continue;
                }
                f[i][s] = min(f[i][s], f[j][s - (1 << (i - 1))] + dis(i, j));
            }
        }
    }
    double ans = inf;
    for(int i = 1; i <= N; i++){
        ans = min(dis(i, 0) + f[i][(1 << N) - 1], ans);
    }
    printf("%.2lf", ans);
    return 0;
}