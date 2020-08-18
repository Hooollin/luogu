//
// P1101.cpp
// Created by Hollin on 7/31/2020
//

#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
const string word = "yizhong";
const int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
char mat[maxn][maxn];
bool res[maxn][maxn];

bool dfs(int x, int y, int dx, int dy, int k, int n)
{
    if (k == word.size())
    {
        return true;
    }
    if (x < 0 || x >= n || y < 0 || y >= n || mat[x][y] != word[k])
    {
        return false;
    }
    if (dfs(x + dx, y + dy, dx, dy, k + 1, n))
    {
        res[x][y] = true;
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 'y')
            {
                for (auto p : dirs)
                {
                    dfs(i, j, p[0], p[1], 0, n);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (res[i][j])
            {
                cout << mat[i][j];
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}