#include <bits/stdc++.h>
using namespace std;
double distance(pair<int, int> &p1, pair<int, int> &p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
double rec(vector<pair<int, int>> &vec, int L, int R)
{
    if (L == R)
    {
        return -1;
    }
    int mid = (L + R) / 2;
    double left_d = rec(vec, L, mid);
    double right_d = rec(vec, mid + 1, R);
    if (left_d == right_d && left_d == -1)
    {
        return distance(vec[L], vec[R]);
    }
    int d;
    if (left_d == -1)
    {
        d = right_d;
    }
    else if (right_d == -1)
    {

        d = left_d;
    }
    else
    {
        d = min(left_d, right_d);
    }
}
void inlet(vector<pair<int, int>> &vec)
{
    cout << rec(vec, 0, vec.size() - 1);
}

int main()
{
    vector<pair<int, int>> vec;
    sort(vec.begin(), vec.end());
    return 0;
}