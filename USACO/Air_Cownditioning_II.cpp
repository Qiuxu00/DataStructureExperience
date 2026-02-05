#include <bits/stdc++.h>
using namespace std;

int ac_II(vector<vector<int>> &cow, vector<vector<int>> &ac)
{

    int min_cost = __INT_MAX__;
    for (int b = 0; b < (1 << ac.size()); b++)
    {
        vector<int> cow_room(100, 0);
        int cost = 0;
        for (int i = 0; i < ac.size(); i++)
        {
            if (b & (1 << i))
            {
                cost += ac[i][3];
                for (int ii = ac[i][0] - 1; ii < ac[i][1]; ii++)
                {
                    cow_room[ii] += ac[i][2];
                }
            }
        }
        if (cost >= min_cost)
        {
            continue;
        }
        bool flag = true;
        for (auto i : cow)
        {
            for (int ii = i[0] - 1; ii < i[1]; ii++)
            {
                if (cow_room[ii] < i[2])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag && cost < min_cost)
        {
            min_cost = cost;
        }
    }
    return min_cost;
}

int main()
{
    return 0;
}