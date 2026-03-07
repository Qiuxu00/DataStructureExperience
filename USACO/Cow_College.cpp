#include <bits/stdc++.h>
using namespace std;

void cc(vector<int> &cow, int n)
{
    sort(cow.begin(), cow.end());
    long long sum = 0;
    long long result = 0;
    for (int i = 0; i < cow.size(); i++)
    {
        if (i > 0 && cow[i] == cow[i - 1])
        {
            continue;
        }
        long long temp = cow[i] * (n - i);
        if (temp > sum)
        {
            result = cow[i];
            sum = temp;
        }
    }
    cout << sum << " " << result << endl;
}

int main()
{
    vector<int> cow = {1, 6, 4, 6};
    cc(cow, 4);
    return 0;
}