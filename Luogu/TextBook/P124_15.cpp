#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> B = {5, 10, 3, 8, 1, 6};
    vector<int> S = {2, 9, 1, 7, 0, 5};
    vector<int> left_min_pos(B.size());
    vector<int> right_max_pos(B.size());
    int min_ = __INT_MAX__;
    int max_ = 0;
    int min_pos = -1;
    int max_pos = -1;

    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] < min_)
        {
            min_ = B[i];
            min_pos = i;
        }
        left_min_pos[i] = min_pos;
    }
    for (int i = B.size() - 1; i >= 0; i--)
    {
        if (S[i] > max_)
        {
            max_ = S[i];
            max_pos = i;
        }
        right_max_pos[i] = max_pos;
    }
    int result = S[right_max_pos[0]] - B[left_min_pos[0]];
    int sold_p = right_max_pos[0];
    int buy_p = left_min_pos[0];
    for (int i = 1; i < B.size(); i++)
    {
        if (S[right_max_pos[i]] - B[left_min_pos[i]] > result)
        {
            result = S[right_max_pos[i]] - B[left_min_pos[i]];
            sold_p = right_max_pos[i];
            buy_p = left_min_pos[i];
        }
    }
    cout << "Buy in at " << buy_p + 1 << endl
         << "Sold out at " << sold_p + 1 << endl
         << "Get " << result << endl;
    return 0;
}