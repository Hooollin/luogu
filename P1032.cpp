//
// P1032.cpp 
// Created by Hollin on 8/4/2020
//
#include <bits/stdc++.h>
using namespace std;
map<string, set<string>> m;
map<string, int> mem;
set<string> vis;
int ans = 0;

int main(){
    string A, B;
    cin >> A >> B;
    string line;
    while(getline(cin, line)){
        string Ak, Bk;
        stringstream ss(line);
        ss >> Ak >> Bk;
        if(m.find(Ak) == m.end()){
            m[Ak] = set<string>();
        }
        m[Ak].insert(Bk);
    }
    queue<string> q;
    q.push(A);
    vis.insert(A);
    bool found = false;
    while(!q.empty() && ans <= 10){
        int size = q.size();
        ans += 1;
        while(size-- > 0){
            string now = q.front();q.pop();
            for(int i = 0; i < now.size(); i++){
                string former = now.substr(0, i);
                for(int j = i + 1; j <= now.size(); j++){
                    string curr = now.substr(i, j - i);
                    string end = now.substr(j, now.size() - j);
                    if(m.count(curr)){
                        for(auto middle : m[curr]) {
                            string next = former + middle + end;
                            //cout << next << endl;
                            if(next == B){
                                found = true;
                            }
                            if(vis.find(next) == vis.end()) {
                                q.push(next);
                                vis.insert(next);
                            }
                        }
                    }
                }
            }
        }
        if(found){
            break;
        }
    }
    if(ans == 11 || !found){ cout << "NO ANSWER!" << endl; }else cout << ans << endl;
    return 0;
}