#include <iostream>
#include <vector>
#include <queue>
using namespace std;

auto cmp = [](const pair<int, int> p1, const pair<int, int> p2)
{
    return p1.second > p2.second;
};

int Search(vector<vector<int>> &test, int n, int k)
{
    using MyPQ = priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>;
    MyPQ pq(cmp);
    vector<int> pos(n, 0); // 利用位置寄存器来实现不破坏原数组并且能够极大的降低复杂度，erase是O（n）的时间复杂度
    for (int i = 0; i < n; i++)
    {
        pq.push({i, test[i].front()});
    }
    int count = 1;
    while (count != k)
    {
        int num = pq.top().first;
        pq.pop();
        pos[num]++;
        if (pos[num] < n)
        {
            pq.push({num, test[num][pos[num]]});
        }
        count++;
    }
    return pq.top().second;
}

int main()
{
    vector<vector<int>> test = {
        {1, 5, 9, 10, 15},
        {2, 6, 10, 11, 16},
        {3, 7, 12, 13, 20},
        {8, 12, 14, 15, 21},
        {10, 13, 18, 19, 25}};
    cout << Search(test, 3, 8) << endl;
    return 0;
}