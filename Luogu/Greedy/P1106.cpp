#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num = "5007489";
    int n = 3;
    int left = num.size() - n;
    if (left == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (left < 0)
    {
        cout << "n is too large" << endl;
        return 0;
    }
    for (int i = 0; i < left; i++)
    {
    }

    return 0;
}