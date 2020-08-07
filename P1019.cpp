//
// P1019.cpp 
// Created by Hollin on 7/30/2020
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;
vector<string> words(maxn);
vector<int> cnts(maxn);
int ans = 0;

int concat(string str1, string str2){
        for(int i = 1; i < min(str1.length(), str2.length()); i++) {//重叠长度从1开始，直到最短的字符串长度-1（因为不能包含）
            int flag = 1;
            for(int j = 0; j < i; j++)
                if(str1[str1.length() - i + j] != str2[j]) flag = 0;//逐个检测是否相等
            if(flag) return i;//检测完毕相等则立即return
        }
        return 0;//无重叠部分，返回0
}

void dfs(string last, int now, int k, int n){
    ans = max(now, ans);
    for(int i = 0; i < n; i++){
        if(cnts[i] > 0){
            int ss = concat(last, words[i]);
            if(ss == 0){
                continue;
            }
            cnts[i] -= 1;
            dfs(words[i], now + words[i].size() - ss, k + 1, n);
            cnts[i] += 1;
        }
    }
}

int main(){
    int n;
    char begin;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> words[i];
        cnts[i] = 2;
    }
    cin >> begin;
    for(int i = 0; i < n; i++) {
        if(words[i][0] != begin) continue;
        cnts[i] -= 1;
        dfs(words[i], words[i].size(), 1, n);
        cnts[i] += 1;
    }
    cout << ans << endl;
    return 0;
}
