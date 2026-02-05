#include <bits/stdc++.h>
using namespace std;

int wdcc(vector<char> &c)
{
    int result = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < c.size(); i++)
    {
        if (map[c[i]] == 0)
        {
            map[c[i]] += (i + 1);
        }

        else
        {

            for (int ii = map[c[i]]; ii < i; ii++)
            {
                if (map[c[ii]] != 0)
                {
                    result++;
                }
            }
            map[c[i]] = 0;
        }
    }

    return result;
}

int main()
{
    vector<char> c(52);
    for (char &i : c)
    {
        cin >> i;
    }
    cout << wdcc(c) << endl;
    return 0;
}