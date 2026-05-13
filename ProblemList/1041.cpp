#include <bits/stdc++.h>
using namespace std;

void solve(vector<double> &res)
{
    int n, m;
    cin >> n >> m;
    vector<int> nums_1(n);
    vector<int> nums_2(m);
    for (int &i : nums_1)
    {
        cin >> i;
    }
    for (int &i : nums_2)
    {
        cin >> i;
    }
    int whole = n + m;
    int k = whole / 2;
    int ptr_1 = 0;
    int ptr_2 = 0;
    int in = 0;
    stack<int> st;
    while (ptr_1 < n && ptr_2 < m)
    {
        nums_1[ptr_1] < nums_2[ptr_2] ? st.push(nums_1[ptr_1++]) : st.push(nums_2[ptr_2++]);
        in++;
        if (in == k + 1)
        {
            break;
        }
    }

    if (ptr_1 == n)
    {
        while (in < k + 1)
        {
            st.push(nums_2[ptr_2++]);
            in++;
        }
    }
    else if (ptr_2 == m)
    {

        while (in < k + 1)
        {
            st.push(nums_1[ptr_1++]);
            in++;
        }
    }
    if ((n + m) % 2)
    {
        res.push_back((double)st.top());
    }
    else
    {
        double t1 = (double)st.top();
        st.pop();
        double t2 = st.top();
        res.push_back((t1 + t2) / 2);
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<double> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (double i : res)
    {
        printf("%.5f\n", i);
    }
    return 0;
}