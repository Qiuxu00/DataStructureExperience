#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    // 1. 读入 n (头数) 和 m (骑士数)
    if (!(cin >> n >> m))
        return 0;

    vector<int> heads(n);
    vector<int> z(m);

    for (int i = 0; i < n; i++)
        cin >> heads[i];
    for (int i = 0; i < m; i++)
        cin >> z[i];
    int ptr_h = 0;
    int ptr_z = 0;
    int result = 0;
    sort(heads.begin(), heads.end());
    sort(z.begin(), z.end());
    for (; ptr_z < z.size(); ptr_z++)
    {
        if (ptr_h < heads.size() && z[ptr_z] >= heads[ptr_h])
        {
            result += z[ptr_z];
            ptr_h++;
        }
    }
    if (ptr_h < heads.size())
    {
        cout << "you died!" << endl;
        return 0;
    }
    cout << result << endl;
    return 0;
}