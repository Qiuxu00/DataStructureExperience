#include <bits/stdc++.h>
using namespace std;

int LB(vector<pair<int, int>> &cow, int B)
{
    int max_ = __INT_MAX__;
    for (int col = 0; col <= B; col += 2)
    {
        for (int row = 0; row <= B; row += 2)
        {
            int lup(0), rup(0), ldo(0), rdo(0);
            for (auto p : cow)
            {
                if (p.first < col & p.second < row)
                {
                    lup++;
                }
                if (p.first > col & p.second < row)
                {
                    rup++;
                }
                if (p.first<col & p.second> row)
                {
                    ldo++;
                }
                if (p.first > col & p.second > row)
                {
                    rdo++;
                }
            }
            int temp = max({lup, ldo, rup, rdo});
            if (temp == cow.size() / 4 + 1)
            {
                return cow.size() / 4 + 1;
            }
            if (temp < max_)
            {
                max_ = temp;
            }
        }
    }
    return max_;
}

int main()
{
    int n, b;
    cin >> n >> b;
    vector<pair<int, int>> v(n);
    for (auto &p : v)
    {
        cin >> p.first >> p.second;
    }
    cout << LB(v, b) << endl;
    return 0;
}