//
// P5266.cpp 
// Created by Hollin on 8/18/2020
// 
#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> score;
    int n;
    cin >> n;
    while(n-- > 0){
        int type;
        string name;
        cin >> type;
        if(type != 4){
            cin >> name;
        }
        if(type == 1){
            int s;
            cin >> s;
            score[name] = s;
            cout << "OK" << endl;
        }else if(type == 2){
            if(score.count(name) == 0){
                cout << "Not found" << endl;
            }else{
                cout << score[name] << endl;
            }
        }else if(type == 3){
            if(score.count(name) == 0){
                cout << "Not found" << endl;
            }else{
                score.erase(name);
                cout << "Deleted successfully" << endl;
            }
        }else{
            cout << score.size() << endl;
        }
    }
    return 0;
}