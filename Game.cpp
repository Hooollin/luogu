//
// Created by lan-c on 7/26/2020.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T-- > 0){
        double curr;
        scanf("%lf", &curr);
        if(curr > 1.0){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    return 0;
}

