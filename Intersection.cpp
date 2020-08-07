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
        scanf("%d", &n);
        int maxa = 0, maxb = 0;
        for(int i = 0; i < n; i++){
            int road, pos;
            scanf("%d%d", &road, &pos);
            if(road == 1){
                maxa = max(pos, maxa);
            }else{
                maxb = max(pos, maxb);
            }
        }
        if(maxa == 0){
            printf("%d\n", maxb + 2);
            continue;
        }else if(maxb == 0){
            printf("%d\n", maxa + 1);
            continue;
        }
        if(maxa >= maxb){
            printf("%d\n", maxa + 2);
        } else{
            printf("%d\n", maxb + 2);
        }
    }
    return 0;
}

