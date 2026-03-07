#include <bits/stdc++.h>
using namespace std;
auto cmp = [&](pair<string, int> a, pair<string, int> b) -> bool
{ return a.second > b.second; };
string dbl(vector<vector<string>> &d)
{
    unordered_map<string, int> map = {{"Bessie", 0}, {"Maggie", 0}, {"Elsie", 0}, {"Henrietta", 0}, {"Gertie", 0}, {"Daisy", 0}, {"Annabelle", 0}};
    for (auto i : d)
    {
        map[i[0]] += stoi(i[1]);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
    for (auto i : map)
    {
        q.push(i);
    }
    int Min = q.top().second;
    int nums = 0;
    while (!q.empty() && q.top().second == Min)
    {
        q.pop();
    }
    pair<string, int> temp;
    if (!q.empty())
    {
        temp = q.top();
        q.pop();
    }
    else
    {
        temp = {"shiiiiit", -2};
    }
    pair<string, int> temp_2;

    if (q.empty())
    {
        temp_2 = {"shit", -1};
    }
    else
    {
        temp_2 = q.top();
    }
    if (temp.second == temp_2.second)
    {
        return "Tie";
    }
    else
    {
        return temp.first;
    }
}

int main()
{
    return 0;
}