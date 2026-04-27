#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &res)
{
    string S;
    getline(cin, S);
    int result = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] - '0' <= 9 && S[i] - '0' >= 0)
        {
            result++;
        }
    }
    res.push_back(result);
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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