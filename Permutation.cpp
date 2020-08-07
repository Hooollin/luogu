//
// Created by lan-c on 7/26/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d",  &T);
    while(T-- > 0){
        int n, m;
        scanf("%d%d", &n, &m);
        m = min(n / 2, m);
        printf("%lld\n", 1LL * (n - 2 * m + n - 1) * m);
    }
    return 0;
}


