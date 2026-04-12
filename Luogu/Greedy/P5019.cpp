#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> num = {4, 3, 2, 5, 3, 5};
    int result = 0;
    int start = 0;
    for (; start < num.size();)
    {
        if (num[start] == 0)
        {
            start++;
            continue;
        }
        int end = start;
        while (num[end] != 0)
        {
            num[end]--;
            end++;
        }
        result++;
    }
    cout << result << endl;
    return 0;
}