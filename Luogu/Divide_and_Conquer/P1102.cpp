#include <bits/stdc++.h>
using namespace std;

int left_(vector<int> &vec, int target, int L, int R)
{
    if (L == R)
    {
        if (vec[L] == target)
        {
            return L;
        }
        else
        {
            return -1;
        }
    }
    if (L > R)
    {
        return -1;
    }
    int mid = L + (R - L) / 2;
    if (vec[mid] >= target)
    {
        return left_(vec, target, L, mid);
    }
    else
    {
        return left_(vec, target, mid + 1, R);
    }
}
int right_(vector<int> &vec, int target, int L, int R)
{
    if (L == R)
    {
        if (vec[L] == target)
        {
            return L;
        }
        else
        {
            return -1;
        }
    }
    if (L > R)
    {
        return -1;
    }
    int mid = L + (R - L + 1) / 2;
    if (vec[mid] <= target)
    {
        return right_(vec, target, mid, R);
    }
    else
    {
        return right_(vec, target, L, mid - 1);
    }
}

long long fun_1(vector<int> &vec_o, vector<int> &vec_p)
{
    long long result = 0;
    for (int i = 0; i < vec_o.size(); i++)
    {
        int left = left_(vec_p, vec_o[i], 0, vec_p.size() - 1);
        int right = right_(vec_p, vec_o[i], 0, vec_p.size() - 1);
        if (left == -1 && right == -1)
        {
            continue;
        }
        result += (right - left + 1);
    }
    return result;
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> vec_ordin(n);
    vector<int> vec_plusc(n);
    for (int &i : vec_ordin)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        vec_plusc[i] = vec_ordin[i] + c;
    }

    sort(vec_plusc.begin(), vec_plusc.end());
    cout << fun_1(vec_ordin, vec_plusc) << endl;
    return 0;
}