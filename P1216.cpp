#include <iostream>

using namespace std;

const int maxr = 1e3 + 5;

int rows[maxr][maxr];
int dp[maxr][maxr];

int main(){
    int r;
    cin >> r;
    memset(rows, 0, sizeof(rows));

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= i; j++){
            cin >> rows[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[1][1] = rows[1][1];
    int ans = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i][j], rows[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]));
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << endl; 
    return 0;
}