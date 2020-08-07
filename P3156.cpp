//
// P3156.cpp 
// Created by Hollin on 7/28/2020
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    int arr[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    while(t-- > 0){
        int idx;
        cin >> idx;
        cout << arr[idx] << endl;
    }
    return 0;
}
