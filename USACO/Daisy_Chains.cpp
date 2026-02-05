#include <bits/stdc++.h>
using namespace std;

int dc(vector<double> &p, int n)
{
    int result = n;
    vector<double> sum;
    sum = p;

    for (double step = 1; step <= n - 1; step++)
    {

        for (int cur = 0; cur <= n - 1 - step; cur++)
        {
            sum[cur] += p[cur + step];
            double val = sum[cur] / (step + 1);
            for (int count = 0; count <= step; count++)
            {
                if (p[cur + count] == val)
                {
                    result++;
                    break;
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<double> p = {1, 1, 2, 3};
    cout << dc(p, 4) << endl;
    return 0;
}