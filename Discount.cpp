//
// Created by lan-c on 7/26/2020.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T-- > 0){
        int n;
        double ans = 0.;
        scanf("%d", &n);
        while(n-- > 0){
            double t, dis;
            scanf("%lf%lf", &t, &dis);
            ans = max(ans, (1 - dis) / (t + 1 - dis));
        }
        printf("%.5lf\n", ans);
    }
    return 0;
}
