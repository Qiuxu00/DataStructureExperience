#include <bits/stdc++.h>
using namespace std;

int main()
{
    // --- 补齐的 Input 部分 ---
    string num;
    int n;
    if (!(cin >> num >> n))
        return 0;
    // -----------------------
    int left = num.size() - n;
    if (left == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (left < 0)
    {
        return 0;
    }
    int j = 0;
    vector<char> result;
    for (int i = 0; i < left; i++)
    {
        int min_pos = -1;
        int min_ = __INT_MAX__;
        for (; j <= num.size() - left + i; j++)
        {
            if (num[j] - '0' < min_)
            {
                min_ = num[j] - '0';
                min_pos = j;
            }
        }
        if (result.empty())
        {
            if (num[min_pos] != '0')
            {
                result.push_back(num[min_pos]);
            }
        }
        else
        {
            result.push_back(num[min_pos]);
        }
        j = min_pos + 1;
    }
    if (result.empty())
    {
        cout << '0' << endl;
        return 0;
    }
    for (auto i : result)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}