#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "GHHHGHH";
    string b = "HHGGGHH";
    int result = 0;
    for (int i = 0; i < a.size();)
    {
        if (a[i] != b[i])
        {
            result++;
            while (i < a.size() && a[i] != b[i])
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    cout << result << endl;
    return 0;
}