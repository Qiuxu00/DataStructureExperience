#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int m, n, target;
    cin >> m >> n >> target;
    vector<vector<int>> mat(m, vector<int>(n));
    for (auto &v : mat)
    {
        for (auto &i : v)
        {
            cin >> i;
        }
    }
    int ptr_1 = m - 1;
    int ptr_2 = 0;
    while (ptr_1 >= 0 && ptr_2 < n)
    {
        if (mat[ptr_1][ptr_2] > target)
        {
            ptr_1--;
        }
        else if (mat[ptr_1][ptr_2] < target)
        {
            ptr_2++;
        }
        else
        {
            res.push_back(1);
            return;
        }
    }
    res.push_back(0);
    return;
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
        if (i)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}