#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e9 + 50;
long long N, K;

unordered_map<int, int> row, col;


int main(){
    scanf("%d%d", &N, &K);

    long long ans = 0;
    for(int i = 0; i < K; i++){
        int R, C;
        scanf("%d%d", &R, &C);
        row[R] += 1;
        col[C] += 1;
    }
    int uniR = row.size(), uniC = col.size();
    ans = N * N - (N - uniR) * (N - uniC);
    cout << ans << endl;
    return 0;
}