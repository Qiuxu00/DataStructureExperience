#include <bits/stdc++.h>
using namespace std;

void aa(vector<vector<int>> &q)
{
    map<int, int> a;
    for (auto i : q)
    {
        if (i[0])
        {
            cout << a[i[1]] << endl;
        }
        else
        {
            a[i[1]] = i[2];
        }
    }
}

int main()
{
    int n = 8;
    vector<vector<int>> q = {{0, 1, 2},
                             {1, 1},
                             {1, 2},
                             {0, 2, 3},
                             {1, 1},
                             {1, 2},
                             {
                                 0,
                                 2,
                                 1,
                             },
                             {1, 2}};
    aa(q);
    return 0;
}