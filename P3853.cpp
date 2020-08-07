//
// Created by lan-c on 7/25/2020.
//

#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int> arr, int len, int k){
    int cnt = 0;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] - arr[i - 1] > len){
            int d = arr[i] - arr[i - 1];
            if(d % len == 0){
                cnt += d / len - 1;
            }else cnt += d / len;
        }
    }
    return cnt <= k;
}

int main(){
    int L, N, K;
    cin >> L >> N >> K;
    vector<int> arr(N);
    int s = 1, e = L;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    int ans = e;
    while(s <= e){
        int mid = (s + e) / 2;
        if(valid(arr, mid, K)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

