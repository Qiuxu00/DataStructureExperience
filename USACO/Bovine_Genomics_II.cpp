#include <bits/stdc++.h>
using namespace std;

int bg_2(vector<vector<char>> &c, int n, int m)
{
    int result = 0;
    for (int first = 0; first <= m - 3; first++)
    {
        for (int med = first + 1; med <= m - 2; med++)
        {
            for (int END = med + 1; END <= m - 1; END++)
            {
                bool flag = true;
                unordered_map<string, bool> map;
                int nums = 0;
                string temp;
                for (int row = 0; row < n; row++)
                {
                    temp = {c[row][first], c[row][med], c[row][END]};
                    if (!map[temp])
                    {
                        nums++;
                        map[temp] = true;
                    }
                }
                if (nums >= 64)
                {
                    break;
                }
                for (int row = n; row < 2 * n; row++)
                {
                    temp = {c[row][first], c[row][med], c[row][END]};
                    if (map[temp])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                {
                    continue;
                }
                else
                {
                    result++;
                }
            }
        }
    }
    return result;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(2 * n, vector<char>(m));
    for (vector<char> &v : c)
    {
        for (char &i : v)
        {
            cin >> i;
        }
    }
    cout << bg_2(c, n, m) << endl;
    return 0;
}