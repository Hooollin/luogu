//
// P2058.cpp 
// Created by Hollin on 8/7/2020
//
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
unordered_set<int> now;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> q(N, vector<int>(0));
    vector<int> times(N);
    for(int i = 0; i < N; i++){
        cin >> times[i];
        int k;
        cin >> k;
        while(k-- > 0){
            int t;
            cin >> t;
            q[i].push_back(t);
        }
    }
    int gap = 86400;
    for(int i = 0, j = 0; j < times.size(); j++){
        for(int k = 0; k < q[j].size(); k++){
            //cout << "q[" << j << "]: " << q[j][k] << ends;
            if(m.count(q[j][k]) == 0){
                m[q[j][k]] = 0;
            }
            m[q[j][k]] += 1;
            now.insert(q[j][k]);
        }
        //cout << endl;
        while(i < j && times[j] - times[i] >= gap){
            for(int k = 0; k < q[i].size(); k++){
                m[q[i][k]] -= 1;
                if(m[q[i][k]] == 0){
                    now.erase(q[i][k]);
                }
            }
            i += 1;
        }
        cout << now.size() << endl;
    }
    return 0;
}