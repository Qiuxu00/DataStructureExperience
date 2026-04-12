#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int N, T;
    // cin >> N >> T;
    int result = 0;
    int N = 4, T = 50;
    vector<int> nums(N);
    vector<int> value(N);
    nums = {10, 20, 25, 15};
    value = {60, 100, 100, 45};
    vector<pair<int, int>> per(N);
    for (int i = 0; i < N; i++)
    {
        per.push_back({value[i] / nums[i], nums[i]});
    }
    sort(per.begin(), per.end());
    while (T > 0)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            if (T >= per[i].second)
            {
                result += per[i].first * per[i].second;
                T -= per[i].second;
            }
            else if (T > 0)
            {
                result += per[i].first * T;
                T == 0;
            }
            else
            {
                break;
            }
        }
    }
    cout << result << endl;
    return 0;
}