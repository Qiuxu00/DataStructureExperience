#include <bits/stdc++.h>
using namespace std;

int result = 0;
void merge(vector<int> &vec, int L, int mid, int R)
{
    vector<int> temp;
    int ptr_l = L;
    int ptr_r = mid + 1;
    while (ptr_l <= mid || ptr_r <= R)
    {
        if (ptr_r <= R && ptr_l <= mid)
        {
            if (vec[ptr_r] < vec[ptr_l])
            {
                temp.push_back(vec[ptr_r]);
                result += (mid - ptr_l + 1);
                ptr_r++;
                continue;
            }
            else
            {
                temp.push_back(vec[ptr_l]);
                ptr_l++;
                continue;
            }
        }
        if (ptr_r > R)
        {
            while (ptr_l <= mid)
            {
                temp.push_back(vec[ptr_l]);
                ptr_l++;
            }
        }
        if (ptr_l > mid)
        {
            while (ptr_r <= R)
            {
                temp.push_back(vec[ptr_r]);
                ptr_r++;
            }
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        vec[L + i] = temp[i];
    }
}

void merge_rec(vector<int> &vec, int L, int R)
{
    if (L == R)
    {
        return;
    }
    int mid = (L + R) / 2;
    merge_rec(vec, L, mid);
    merge_rec(vec, mid + 1, R);
    merge(vec, L, mid, R);
}

void merge_inlet(vector<int> &vec)
{
    merge_rec(vec, 0, vec.size() - 1);
    cout << result << endl;
}

int main()
{
    vector<pair<int, int>> vec = {{1, 3}, {2, 1}, {3, 6}, {4, 8}, {5, 2}, {6, 5}, {7, 4}, {8, 7}};
    sort(vec.begin(), vec.end());
    vector<int> v;
    for (auto i : vec)
    {
        v.push_back(i.second);
    }
    merge_inlet(v);
    return 0;
}