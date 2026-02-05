#include <bits/stdc++.h>
using namespace std;
void cq_r(vector<vector<char>> &c, int n, vector<bool> &col, vector<bool> &diag_down, vector<bool> &diag_up, int cur_times, int &result)
{
    if (cur_times == n)
    {
        result++;
        return;
    }
    for (int i = 0; i < c.size(); i++)
    {
        if (col[i] || c[cur_times][i] == '*' || diag_down[i - cur_times + n - 1] || diag_up[cur_times + i])
        {
            continue;
        }
        col[i] = true;
        diag_down[i - cur_times + n - 1] = true;
        diag_up[cur_times + i] = true;
        cq_r(c, n, col, diag_down, diag_up, cur_times + 1, result);
        col[i] = false;
        diag_down[i - cur_times + n - 1] = false;
        diag_up[cur_times + i] = false;
    }
}
int cq(vector<vector<char>> &c, int n)
{
    vector<bool> col(c.size(), false);
    vector<bool> diag_down(2 * c.size() - 1, false);
    vector<bool> diag_up(2 * c.size() - 1, false);
    int cur_times(0), result(0);
    cq_r(c, n, col, diag_down, diag_up, cur_times, result);
    return result;
}

int main()
{
    int n = 8; // 题目给定是 8x8
    vector<vector<char>> c(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line; // 读取一行字符，例如 "........"
        for (int j = 0; j < n; j++)
        {
            c[i][j] = line[j];
        }
    }
    cout << cq(c, n) << endl;
    return 0;
}