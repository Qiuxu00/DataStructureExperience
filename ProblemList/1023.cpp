#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int n, E, s, t, M;
    cin >> n >> E >> s >> t >> M;
    vector<int> B(n);
    for (int &i : B)
    {
        cin >> i;
    }
    vector<vector<int>> road(E, vector<int>(3));
    for (auto &v : road)
    {
        for (int &i : v)
        {
            cin >> i;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (int i : res)
    {
        cout << i << endl;
    }
    return 0;
}