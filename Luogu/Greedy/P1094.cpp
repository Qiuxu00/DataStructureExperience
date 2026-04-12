#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w = 100;
    int n = 9;
    vector<int> value = {90,
                         20,
                         20,
                         30,
                         50,
                         60,
                         70,
                         80,
                         90};
    vector<bool> choosed(value.size());
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!choosed[i])
        {
            int limit = w - value[i];
            int max_ = 0;
            int max_pos = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (!choosed[j])
                {
                    if (value[j] > max_ && value[j] <= limit)
                    {
                        max_ = value[j];
                        max_pos = j;
                    }
                }
            }
            if (max_pos != -1)
            {
                choosed[max_pos] = 1;
            }
            result++;
            choosed[i] = 1;
        }
    }
    cout << result << endl;
    return 0;
}