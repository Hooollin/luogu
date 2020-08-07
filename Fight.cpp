#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int n = 2;
        vector<vector<vector<int>>> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = vector<vector<int>>(n);
            for(int j = 0; j < dp[i].size(); j++){
                dp[i][j] = vector<int>(n);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    dp[i][j][k] = 10000;
                }
            }
        }
        for(int i = 0; i < n; i++){
            dp[i][0][0] = 0;
            dp[0][0][i] = 0;
            dp[0][i][0] = 0;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= x; j++){
                dp[i][j][0] = 1;
                dp[i][0][j] = 1;
            }
            for(int j = 1; j <= y; j++){
                dp[0][i][j] = 1;
                dp[j][i][0] = 1;
            }
            for(int j = 1; j <= z; j++){
                dp[0][j][i] = 1;
                dp[j][0][i] = 1;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(i == 0 && j == 0){
                        continue;
                    }
                    if(i == 0 && k == 0){
                        continue;
                    }
                    if(k == 0 && j == 0){
                        continue;
                    }
                    if(j > x){
                        dp[i][j][k] = min(dp[i][j][k], dp[i][j - x][k] + 1);
                    }
                    if(j > z){
                        dp[i][j][k] = min(dp[i][j][k], dp[i][j - z][k] + 1);
                    }
                    if(i > y){
                        dp[i][j][k] = min(dp[i][j][k], dp[i - y][j][k] + 1);
                    }
                    if(i > z){
                        dp[i][j][k] = min(dp[i][j][k], dp[i - z][j][k] + 1);
                    }
                    if(k > x){
                        dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - x] + 1);
                    }
                    if(k > y){
                        dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - y] + 1);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    cout << dp[i][j][k] << ends;
                }
                cout << endl;
            }
            cout << endl;
        }
        printf("%d\n", dp[n - 1][n - 1][n - 1]);
   }
    return 0;
}

