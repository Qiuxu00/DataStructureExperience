#include <bits/stdc++.h>
using namespace std;

int bg(vector<vector<char>> &g, int n, int m)
{
    int result = 0;
    for (int col = 0; col < m; col++)
    {
        bool flag = true;
        unordered_map<char, bool> m;
        m.clear();
        int num = 0;
        for (int row = 0; row < n; row++)
        {
            if (!m[g[row][col]])
            {
                m[g[row][col]] = true;
                num++;
            }
        }
        if (num == 4)
        {
            continue;
        }
        for (int row = n; row < 2 * n; row++)
        {
            if (m[g[row][col]])
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            continue;
        }
        else
        {
            result++;
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(2 * n, vector<char>(m));
    for (vector<char> &i : g)
    {
        for (char &ii : i)
        {
            cin >> ii;
        }
    }
    cout << bg(g, n, m) << endl;
    return 0;
}
