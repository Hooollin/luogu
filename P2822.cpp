#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 2e3 + 50, maxm = 2e3 + 50;
int n, m, k;
long long c[maxn][maxm], f[maxn][maxm];

void cal(){
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    for(int i = 0; i <= maxn - 50; i++){
        c[i][0] = 1;
    }
    // c[i][j] = c[i - 1][j] + c[i - 1][j - 1]
    for(int i = 1; i <= maxn - 50; i++){
        for(int j = 1; j <= min(i, maxm - 50); j++){
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
            
        }
    }
    for(int i = 1; i <= maxn - 50; i++){
        for(int j =1; j < min(i, maxm - 50); j++){
            f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
            if(c[i][j] == 0){
                f[i][j] += 1;
            }
        }
        f[i][i + 1] = f[i][i];
    }
}

void solve(){
    cout << f[m][n] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t;
    cin >> t >> k;

    cal();
    for(int _ = 0; _ < t; _++){
        cin >> n >> m;
        solve();
    }
    return 0;
}