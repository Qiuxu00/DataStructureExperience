#include <bits/stdc++.h>
using namespace std;

vector<string> cow = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
void ll(vector<vector<string>> &limit) // 01234567
{
    string cow_ = "01234567";
    unordered_map<string, int> map;
    for (int i = 0; i < 8; i++) // 构造映射表，方便检查限制条件
    {
        map.insert({cow[i], i});
    }
    vector<pair<int, int>> limit_;
    for (auto s : limit)
    {
        limit_.push_back({map[s[0]], map[s[5]]}); // 构造限制对
    }
    do
    {
        vector<int> position(8, 0); // 记录下标号的牛的位置
        for (int i = 0; i < 8; i++)
        {
            position[cow_[i] - '0'] = i;
        }
        bool flag = true;
        for (auto p : limit_) // 检查限制对
        {
            int f = p.first;
            int e = p.second;
            if (abs(position[f] - position[e]) > 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (char s : cow_)
            {
                cout << cow[s - 48] << endl;
            }
            return;
        }
    } while (next_permutation(cow_.begin(), cow_.end()));
}

int main()
{
    return 0;
}