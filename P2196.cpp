#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 25;

int amount[maxn];
int graph[maxn][maxn];
// f[x]:
// f[x] = amount[x]
// i from 1 -> x:
//     if graph[i][x] == 1:
//         f[x] = max(f[x], f[i] + amount[x])

int f[maxn];
int p[maxn];

void print(int n){
    if(p[n] == 0){
        cout << n << " ";
        return;
    }
    print(p[n]);
    cout << n << " ";
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> amount[i];
    }
    for(int i = 1; i <= n; i++){
        graph[i][i] = 1;
        for(int j = i + 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }
    memset(f, 0, sizeof(f));
    memset(p, 0, sizeof(p));
    for(int i = 1; i <= n; i++){
        f[i] = amount[i];
        for(int j = 1; j < i; j++){
            if(graph[j][i] == 1 && f[j] + amount[i] > f[i]){
                f[i] = f[j] + amount[i];
                p[i] = j;
            }
        }
    }
    int maxi = 1;
    for(int i = 1; i <= n; i++){
        if(f[maxi] < f[i]){
            maxi = i;
        }
    }
    print(maxi);
    cout << endl;
    cout << f[maxi] << endl;
    return 0;
}