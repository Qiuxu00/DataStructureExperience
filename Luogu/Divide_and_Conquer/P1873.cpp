#include <bits/stdc++.h>
using namespace std;

long long height(vector<long long> &vec, int target)
{
    vec.push_back(0);
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    vector<long long> gain(vec.size());
    gain[0] = 0;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        gain[i + 1] = (long long)(i + 1) * (vec[i] - vec[i + 1]) + gain[i];
    }
    int lb;
    for (int i = 0; i < vec.size(); i++)
    {
        if (gain[i] == target)
        {
            return vec[i];
        }
        else if (gain[i] > target)
        {
            lb = i;
            break;
        }
    }
    if (lb == vec.size())
    {
        return -1;
    }
    int result = vec[lb];
    int Gain = gain[lb];
    return result + (Gain - target) / lb;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    if (!(cin >> n >> m))
        return 0;

    vector<long long> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    cout << height(vec, m) << "\n";
    return 0;
}