#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (int n : nums)
    {
        freq[n]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // ����С����

    for (auto &p : freq)
    {
        pq.push({p.second, p.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
    return 0;
}