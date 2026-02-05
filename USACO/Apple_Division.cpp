#include <bits/stdc++.h>
using namespace std;

int min = __INT_MAX__;
int ad(vector<int> &a, int n)
{
    int sum_ = 0;
    for (int i : a)
    {
        sum_ += i;
    }
    ad_r(a, n, 0, sum_, 0);

    return;
}
void ad_r(vector<int> &a, int n, int next, int sum, int chosen)
{
    if (::min == 0)
    {
        return;
    }
    if (next == n)
    {
        if (abs(sum - 2 * chosen) < ::min)
        {
            ::min = abs(sum - 2 * chosen);
        }
        return;
    }

    ad_r(a, n, next + 1, sum, chosen + a[next]);
    ad_r(a, n, next + 1, sum, chosen);
}

int ad_bitmask(vector<int> &a, int n, int sums)
{
    int Min = __INT_MAX__;
    for (int b = 0; b < (1 << n); b++)
    {
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            if (b & (1 << i))
            {
                left += a[i];
            }
        }
        if (abs(sums - 2 * left) < Min)
        {
            Min = abs(sums - 2 * left);
        }
        if (Min == 0)
        {
            return 0;
        }
    }
    return Min;
}

int main()
{
    return 0;
}