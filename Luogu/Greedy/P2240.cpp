#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    double T; // 承重也可以用 double 比较稳妥
    cin >> N >> T;

    vector<double> nums(N);
    vector<double> value(N);
    vector<pair<double, double>> per;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i] >> value[i];
        per.push_back({value[i] / nums[i], nums[i]});
    }

    double result = 0;
    sort(per.begin(), per.end());

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
            T = 0;
        }
        else
        {
            break;
        }
    }

    printf("%.2f\n", result);
    return 0;
}