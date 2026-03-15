#include <bits/stdc++.h>
using namespace std;
int rec(vector<int> &vec, int L, int R, int k)
{
    if (L == R)
    {
        return vec[L];
    }
    int pivot = vec[L];
    int lt = L;
    int rt = R;
    int cur = L + 1;
    while (cur <= rt)
    {
        if (vec[cur] < vec[lt])
        {
            swap(vec[cur], vec[lt]);
            cur++;
            lt++;
        }
        else if (vec[cur] > vec[rt])
        {
            swap(vec[cur], vec[rt]);
            rt--;
        }
        else
        {
            cur++;
        }
    }
    if (k < lt)
    {
        return rec(vec, L, lt - 1, k);
    }
    else if (k > rt)
    {
        return rec(vec, rt + 1, R, k);
    }
    else
    {
        return pivot;
    }
}

double qs_inlet(vector<int> &vec)
{
    int size = vec.size();
    if (size % 2 == 1)
    {
        return (double)rec(vec, 0, size - 1, size / 2);
    }
    else
    {
        int a = rec(vec, 0, size - 1, size / 2);
        int b = rec(vec, 0, size - 1, size / 2 - 1);
        return (double)(a + b) / 2;
    }
}
void inlet(vector<pair<int, int>> &vec)
{
    vector<int> vx;
    vector<int> vy;
    for (auto i : vec)
    {
        vx.push_back(i.first);
        vy.push_back(i.second);
    }
    cout << "( " << qs_inlet(vx) << " , " << qs_inlet(vy) << " )" << endl;
}

int main()
{
    vector<pair<int, int>> vec = {{5, 12}, {1, 3}, {9, 8}, {4, 15}, {11, 2}};
    inlet(vec);
    return 0;
}