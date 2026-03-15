#include <bits/stdc++.h>
using namespace std;

int m_distance(pair<int, int> &p1, pair<int, int> &p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int rec(vector<pair<int, int>> &vec, int L, int R)
{
    if (L == R)
    {
        return __INT_MAX__;
    }
    int mid = (L + R) / 2;
    int left_ = rec(vec, L, mid);
    int right_ = rec(vec, mid + 1, R);
    int min_l = min(left_, right_);

    vector<pair<int, int>> strip;
    for (int i = L; i <= R; i++)
    {
        if (abs(vec[i].first - vec[mid].first) < min_l)
        {
            strip.push_back(vec[i]);
        }
    }

    sort(strip.begin(), strip.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < min_l; j++)
        {
            min_l = min(min_l, m_distance(strip[i], strip[j]));
        }
    }
    return min_l;
}

void inlet(vector<pair<int, int>> &vec)
{
    cout << rec(vec, 0, vec.size() - 1) << endl;
}

int main()
{
    vector<pair<int, int>> vec = {{11, 84}, {13, 81}, {100, 34}, {3, 91}, {95, 27}, {83, 50}, {10, 16}, {13, 34}, {30, 67}, {40, 60}};
    sort(vec.begin(), vec.end());
    inlet(vec);
    return 0;
}