#include <bits/stdc++.h>
using namespace std;

double dis(pair<int, int> &p1, pair<int, int> &p2)
{
    return sqrt(pow(((double)p1.first - (double)p2.first), 2) + pow(((double)p1.second - (double)p2.second), 2));
}

double merge(vector<pair<int, int>> &nodes, int L, int R, double min_d)
{
    double delta = min_d;
    double min_x = (double)(nodes[(L + R) / 2].first);
    double res = min_d;

    vector<pair<int, int>> box;

    for (int i = L; i <= R; i++)
    {
        if (abs(nodes[i].first - min_x) < delta)
        {
            box.push_back(nodes[i]);
        }
    }
    sort(box.begin(), box.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    for (int i = 0; i < box.size(); i++)
    {
        for (int j = i + 1; j < box.size() && (box[j].second - box[i].second) < delta; j++)
        {
            res = min(res, dis(box[i], box[j]));
        }
    }
    return res;
}

double rec(vector<pair<int, int>> &nodes, int L, int R)
{
    if (L == R)
    {
        return (double)1e18;
    }
    int mid = (L + R) / 2;
    double left_d = rec(nodes, L, mid);
    double right_d = rec(nodes, mid + 1, R);
    double min_d = min(left_d, right_d);
    return merge(nodes, L, R, min_d);
}

void solve(vector<double> &res)
{
    int n;
    cin >> n;
    vector<pair<int, int>> nodes(n);
    for (auto &p : nodes)
    {
        cin >> p.first;
        cin >> p.second;
    }
    sort(nodes.begin(), nodes.end());
    double d = rec(nodes, 0, n - 1);
    res.push_back(d);
}

int main()
{
    int n;
    cin >> n;
    vector<double> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (auto i : res)
    {
        printf("%.2f\n", i);
    }
    return 0;
}