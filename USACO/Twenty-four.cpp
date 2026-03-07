#include <bits/stdc++.h>
using namespace std;

string ops = "+-*/";

int cal(int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    if (op == '-')
    {
        return a - b;
    }
    if (op == '*')
    {
        return a * b;
    }
    if (op == '/')
    {
        return a / b;
    }
}

int tf_r(vector<int> opd, int times, vector<char> &sign)
{
    if (times == 3)
    {
        return opd[0];
    }
    bool flag = true;
    for (int start = 0; start < 3 - times; start++)
    {
        if (sign[start] == '/' && opd[start] % opd[start + 1] != 0)
        {
            flag = false;
            break;
        }
        opd[start] = cal(opd[start], opd[start + 1], sign[start]);
        tf_r(opd, times + 1, sign);
    }
    if (flag == false)
    {
        return 0;
    }
}
vector<int> tf(vector<vector<int>> &s)
{
    vector<int> result;
    for (auto i : s)
    {
        int max_ = 0;
        bool flag = true;
        for (int first = 0; first < 4; first++)
        {
            for (int second = 0; second < 4; second++)
            {
                for (int third = 0; third < 4; third++)
                {
                    vector<char> sign = {ops[first],
                                         ops[second],
                                         ops[third]};
                    int temp = tf_r(i, 0, sign);
                    if (temp > max_ && temp <= 24)
                    {
                        max_ = temp;
                    }
                    if (max_ == 24)
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        result.push_back(max_);
    }
    return result;
}

int main()
{
    vector<vector<int>> opd = {{6, 6, 6, 6}};
    vector<int> res = tf(opd);
    for (int i : res)
    {
        cout << i << endl;
    }
    return 0;
}