#include <bits/stdc++.h>
using namespace std;

long long check(vector<long long> &num, long long mid)
{
    if (num.size() == 1)
    {
        if (mid >= num[0])
            return 1;
        else
            return __INT_MAX__;
    }
    for (int i = 0; i < num.size(); i++)
    {
        if (mid < num[i])
        {
            return __INT_MAX__;
        }
    }
    long long result = 0;
    for (int i = 0; i < num.size();)
    {
        if (num[i] == mid)
        {
            result++;
            i++;
            continue;
        }
        long long sum = num[i];
        if (i == num.size() - 1)
        {
            result++;
            break;
        }
        for (int j = i + 1; j < num.size(); j++)
        {
            sum += num[j];
            if (sum > mid)
            {
                result++;
                i = j;
                break;
            }
            else if (sum == mid)
            {
                result++;
                i = j + 1;
                break;
            }
            if (j == num.size() - 1)
            {
                result++;
                i = j + 1;
            }
        }
    }
    return result;
}

int main()
{
    long long N, M;
    cin >> N >> M;
    vector<long long> num(N);
    for (long long &i : num)
    {
        cin >> i;
    }
    long long L = __INT_MAX__;
    long long R = 0;
    for (int i : num)
    {
        if (i < L)
        {
            L = i;
        }
        R += i;
    }
    long long ans = 0;
    while (L <= R)
    {
        long long mid = (L + R) / 2;
        if (check(num, mid) > M)
        {
            L = mid + 1;
        }
        else
        {
            ans = mid;
            R = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
