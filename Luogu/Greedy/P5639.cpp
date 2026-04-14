#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (!(cin >> n))
        return 0;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int result = 0;
    if (c[0] == 1)
    {
        result++;
    }
    int cur = c[0];
    for (int p = 0; p < c.size(); p++)
    {
        if (c[p] != cur)
        {
            result++;
            cur = c[p];
        }
    }
    cout << ++result << endl;
    return 0;
}