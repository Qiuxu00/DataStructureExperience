#include <bits/stdc++.h>
using namespace std;

void cs(string &p)
{
    vector<bool> used(p.size(), false); // 记录哪些元素被选中了哪些没有
    vector<string> result;              // 记录所有串
    string cur = {};
    sort(p.begin(), p.end());
    cs_r(p, used, result, cur);
}
void cs_r(string &p, vector<bool> &used, vector<string> &result, string &cur)
{
    if (cur.size() == p.size())
    {
        result.push_back(cur);
        return;
    }
    for (int i = 0; i < p.size(); i++)
    {
        if (used[i] == 1)
        {
            continue;
        }
        if (i > 0 && p[i] == p[i - 1] && used[i - 1] == 0)
        {
            continue;
        }
        cur.push_back(p[i]);
        used[i] == 1;
        cs_r(p, used, result, cur);
        used[i] == 0;
        cur.pop_back();
    }
}

int main()
{
    return 0;
}