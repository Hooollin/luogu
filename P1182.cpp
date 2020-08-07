//
// Created by lan-c on 7/25/2020.
//
#include <bits/stdc++.h>
using namespace std;


bool valid(vector<int> &arr, int sum, int M){
    int total = 0;
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        total += arr[i];
        if(total > sum){
            cnt += 1;
            total = arr[i];
        }
    }
    return cnt <= M;
}


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    long long s = 1, e = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        e += arr[i];
    }
    long long ans = 0;
    while(s <= e){
        long long mid = (s + e) / 2;
        if(valid(arr, mid, M)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

