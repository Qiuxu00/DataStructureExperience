#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    int N;
    cin >> N;
    N *= 2;
    vector<int> point(N);
    for (int &i : point)
    {
        cin >> i;
    }
    stack<int> st;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (point[st.top()] != point[i])
            {
                result += abs(st.top() - i);
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
    }
    res.push_back(result);
}

int main()
{
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        solve(res);
    }
    for (int i : res)
    {
        cout << i << endl;
    }
    return 0;
}