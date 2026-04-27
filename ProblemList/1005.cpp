#include <bits/stdc++.h>
using namespace std;

void rec(vector<int> &vec, int L, int R)
{
    if (L >= R)
    {
        return;
    }

    int pivot = L + (rand() % (R - L + 1));
    swap(vec[pivot], vec[L]);
    int lt = L;
    int rt = R;
    int ptr = lt + 1;
    pivot = vec[L];
    while (ptr <= rt)
    {
        if (vec[ptr] < pivot)
        {
            swap(vec[ptr], vec[lt]);
            lt++;
            ptr++;
        }
        else if (vec[ptr] > pivot)
        {
            swap(vec[ptr], vec[rt]);
            rt--;
        }
        else
        {
            ptr++;
        }
    }
    rec(vec, L, lt - 1);
    rec(vec, rt + 1, R);
}

void solve(vector<vector<int>> &res)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }
    rec(nums, 0, nums.size() - 1);
    res.push_back(nums);
}

void test()
{
    vector<int> nums = {3, 1, 4, 4, 5, 6, 7, 8, 9, 10};
    rec(nums, 0, nums.size() - 1);
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    // int n;
    // cin >> n;
    // vector<vector<int>> res = res;
    // for (int i = 0; i < n; i++)
    // {
    //     solve(res);
    // }
    test();
    return 0;
}