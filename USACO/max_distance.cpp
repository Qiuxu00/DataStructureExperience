#include <bits/stdc++.h>
using namespace std;

int max_d(vector<int> &x, vector<int> &y, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int ii = i + 1; ii < n; ii++)
        {
            max = (pow((x[i] - x[ii]), 2) + pow((y[i] - y[ii]), 2) > max ? pow((x[i] - x[ii]), 2) + pow((y[i] - y[ii]), 2) : max);
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int &i : x)
    {
        cin >> i;
    }
    for (int &i : y)
    {
        cin >> i;
    }

    cout << max_d(x, y, n) << endl;
    return 0;
}