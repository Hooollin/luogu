//
// P1160.cpp 
// Created by Hollin on 7/28/2020
//
#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> q;
    map<int, int> where;
    q.push_back(1);
    where[1] = 0;
    for(int i = 2; i <= N; i++){
        int man, side;
        cin >> man >> side;
        int loc = where[man];
        if(side){
            where[i] = loc + 1;
            q.insert(q.begin() + loc + 1, i);
            for(int k = loc + 2; k < q.size(); k++){
                where[q[k]] = k;
            }
        }else{
            where[i] = loc;
            q.insert(q.begin() + loc, i);
            for(int k = loc + 1; k < q.size(); k++){
                where[q[k]] = k;
            }
        }
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        int man;
        cin >> man;
        if(where[man] == -1){
            continue;
        }
        int loc = where[man];
        where[man] = -1;
        q.erase(q.begin() + loc);
        for(int k = loc; k < q.size(); k++){
            where[q[k]] = k;
        }
    }
    for(int i = 0; i < q.size(); i++){
        cout << q[i] << " ";
    }
    return 0;
}