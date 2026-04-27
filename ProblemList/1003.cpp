#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &res)
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (auto &i : num)
    {
        cin >> i;
    }

    for (int j = 0; j < n - 1; j++)
    {
        if (num[j] > num[j + 1])
        {
            swap(num[j], num[j + 1]);
        }
    }

    res.push_back(num);
}

int main()
{
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto v : res)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}