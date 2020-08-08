//
// P4715.cpp 
// Created by Hollin on 8/8/2020
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)pow(2, 7) + 1;
int arr[maxn];

int dfs(int start, int end, int n){
    //cout << "start, end: " << start << " " << end <<  endl;
    if(start > end){
        return -1;
    }
    if(start == end){
        return start;
    }
    int mid = (start + end) / 2;
    int left = dfs(start, mid, n);
    int right = dfs(mid + 1, end, n);
    if(left == -1 || right == -1){
        return left == -1 ? right : left;
    }
    if(start == 0 && end == n){
        if(arr[left] > arr[right]){
            return right;
        }else{
            return left;
        }
    }else{
        if(arr[left] > arr[right]){
            return left;
        }else{
            return right;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int size = pow(2, n);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << dfs(0, size - 1, size - 1) + 1 << endl;
    return 0;
}