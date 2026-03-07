#include <bits/stdc++.h>
using namespace std;

int pc(vector<vector<int>> &card, int n, int m)
{
    int result = 0;
    vector<int> sum;
    for (int col = 0; col < m; col++)
    {
        sum.clear();
        for (int i = 0; i < n; i++)
        {
            sum.push_back(card[i][col]);
        }
        sort(sum.begin(), sum.end());
        int temp(0);
        for (int ii = 0; ii < n; ii++)
        {
            temp += (1 + 2 * ii - n) * sum[ii];
        }
        result += temp;
    }
    return result;
}

int main()
{
    int n = 3, m = 5;
    vector<vector<int>> vec = {{1, 4, 2, 8, 5}, {7, 9, 2, 1, 4}, {3, 8, 5, 3, 1}};
    cout << pc(vec, n, m) << endl;
    return 0;
}