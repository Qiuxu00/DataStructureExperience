#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long> &res)
{
    int m;
    cin >> m;
    vector<int> s(m);
    vector<int> p(m);
    for (int &i : s)
    {
        cin >> i;
    }
    for (int &i : p)
    {
        cin >> i;
    }
    long long result = 0;
    int ptr_start = 0;
    while (ptr_start < m)
    {
        int ptr_bias = 0;
        while (ptr_bias + ptr_start < m && (long long)s[ptr_start + ptr_bias] >= (long long)s[ptr_start] + ptr_bias)
        {
            result += (long long)p[ptr_bias + ptr_start] * ((long long)s[ptr_start] + (long long)ptr_bias);
            ptr_bias++;
        }
        ptr_start += ptr_bias;
    }
    res.push_back(result);
}
int main()
{
    int n;
    cin >> n;
    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto i : res)
    {
        cout << i << endl;
    }
    return 0;
}