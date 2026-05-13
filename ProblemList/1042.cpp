#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int n;
    cin >> n;
    vector<int> days(n);
    for (int &i : days)
    {
        cin >> i;
    }
    vector<int> dp(n);
    vector<int> cost(3);
    for (int &i : cost)
    {
        cin >> i;
    }
    dp[0] = cost[0];
    for (int i = 1; i < n; i++)
    {
        
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