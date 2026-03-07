#include <bits/stdc++.h>
using namespace std;

int wdccr(vector<pair<int, int>> &cow)
{
    sort(cow.begin(), cow.end());
    int latest_start = 0;
    for (auto i : cow)
    {
        if (i.first >= latest_start)
        {
            latest_start = (i.first + i.second);
        }
        else
        {
            latest_start += i.second;
        }
    }
    return latest_start;
}

int main()
{
    vector<pair<int, int>> cow = {{2, 1}, {8, 3}, {5, 7}};
    cout << wdccr(cow) << endl;
    return 0;
}