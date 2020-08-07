//
// _map.cpp 
// Created by Hollin on 7/26/2020
//
#include <map>
#include <iostream>
#include <string>
using namespace std;

int main(){
    map<int, string> m;
    string now = "";
    for(int i = 0; i < 10; i++){
        now += (char)i + 'a';
        m[i] = now;
    }
    m.erase(m.find(1));
    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}

