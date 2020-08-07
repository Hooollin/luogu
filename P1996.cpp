//
// P1996.cpp 
// Created by Hollin on 7/28/2020
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while(q.size() > 0){
        int k = m - 1;
        while(k-- > 0){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}