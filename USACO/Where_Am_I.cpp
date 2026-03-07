#include <bits/stdc++.h>
using namespace std;

int wa(vector<char> &s, int n)
{
    int result;
    unordered_map<string, int> ex;
    for (int step = 1; step < n + 1; step++)
    {
        bool flag = true;
        for (int start = 0; start <= n - step; start++)
        {
            string in = "";
            for (int st = start; st < start + step; st++)
            {
                in += s[st];
            }
            if (ex.count(in))
            {
                flag = false;
                break;
            }
            else
            {
                ex[in]++;
            }
        }
        ex.clear();
        if (flag)
        {
            result = step;
            break;
        }
    }
    return result;
}

int main()
{
    vector<char> s;
    string temp = "ABCDABC";
    for (int i = 0; i < temp.size(); i++)
    {
        s.push_back(temp[i]);
    }
    cout << wa(s, s.size()) << endl;
    return 0;
}