#include <bits/stdc++.h>
using namespace std;

long long imt2(vector<int> &t)
{
    long long result = 0;
    vector<long long> different(t.size());
    vector<int> map(1000005);
    int dif = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (!map[t[i]])
        {
            dif++;
            map[t[i]] = 1;
        }
        different[i] = dif;
    }
    for (int &i : map)
    {
        i = 0;
    }
    for (int i = t.size() - 1; i >= 1; i--)
    {
        if (map[t[i]] == -1)
        {
            continue;
        }
        if (map[t[i]] == 0)
        {
            map[t[i]] = i;
        }
        else
        {
            result += (different[i] - 1);
            map[t[i]] = -1;
        }
    }

    return result;
}

int main()
{
    vector<int> t = {1, 2, 3, 4, 4, 4};
    cout << imt2(t) << endl;
    return 0;
}