#include <bits/stdc++.h>
using namespace std;

int cg(vector<vector<int>> &p, int k, int n)
{
    int result = 0;

    for (int left = 0; left < n; left++)
    {
        for (int right = left + 1; right < n; right++)
        {
            bool flag = true;
            for (int row = 1; row < k; row++)
            {
                for (int i : p[row])
                {
                    if (i == p[0][right])
                    {
                        flag = false;
                    }
                    if (i == p[0][left] && flag)
                    {
                        break;
                    }
                    else if (i == p[0][left] && !flag)
                    {
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            if (flag)
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    // vector<int> kn(2);
    // for (int &i : kn)
    // {
    //     cin >> i;
    // }
    // int k = kn[0];
    // int n = kn[1];
    int k(3), n(4);
    vector<vector<int>> p(k, vector<int>(n));
    p = {{4, 1, 2, 3}, {4, 1, 3, 2}, {4, 2, 1, 3}};
    // for (vector<int> i : p)
    // {
    //     for (int &ii : i)
    //     {
    //         cin >> ii;
    //     }
    // }
    // cout << cg(p, kn[0], kn[1]) << endl;
    cout << cg(p, k, n) << endl;
    return 0;
}