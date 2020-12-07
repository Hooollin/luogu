#include <iostream>

using namespace std;
const int maxm = 105;
const int maxt = 1005;
int earn[maxm];
int cost[maxm];
/*
 * f[i][T] = max(f[i - 1][T], maxf[i - 1][T - cost[i]]);
 */
int f[maxm][maxt];



int main(){
    int T, M;
    cin >> T >> M;
    for(int i = 1; i <= M; i++){
        cin >> cost[i] >> earn[i];
    }
    int ans = 0;
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= M; i++){
        for(int t = 0; t <= T; t++){
            f[i][t] = f[i - 1][t];
            if(t - cost[i] >= 0){
                f[i][t] = max(f[i - 1][t], earn[i] + f[i - 1][t - cost[i]]);
            }
        }
    }
    cout << f[M][T];
    return 0;
}