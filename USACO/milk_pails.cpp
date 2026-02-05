#include <bits/stdc++.h>
using namespace std;
int milk(vector<int> &b)
{
    int n = b[2] / b[1];
    int result = 0;
    for (int i = n; i >= 0; i--)
    {
        int final = i * b[1];
        final += (b[0] * ((b[2] - final) / b[0]));
        result = (final >= result ? final : result);
    }
    return result;
}

int main()
{
    vector<int> b = {17, 25, 77};
    cout << milk(b) << endl;
    return 0;
}