#include <bits/stdc++.h>
using namespace std;

void solve(vector<double> &res)
{
    int n;
    cin >> n;
    vector<int> pp(n - 1);
    for (int &i : pp)
    {
        cin >> i;
    }
    double result = 0;
    for (int i : pp)
    {
        result += (double)i / 100.0;
    }
    res.push_back(result + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<double> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto i : res)
    {
        printf("%.6f\n", i);
    }
    return 0;
}