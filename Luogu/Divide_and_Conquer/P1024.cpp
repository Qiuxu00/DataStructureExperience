#include <bits/stdc++.h>
using namespace std;

vector<double> result;
const double EPS = 1e-7; // 精度控制

// 使用秦九韶算法计算多项式，假设 pra 为 {a, b, c, d} -> ax^3 + bx^2 + cx + d
double f(const vector<double> &pra, double x)
{
    double res = 0;
    for (double coeff : pra)
    {
        res = res * x + coeff;
    }
    return res;
}

// 标准二分法
double bisection(const vector<double> &pra, double L, double R)
{
    while (R - L > 1e-4)
    { // 题目一般要求保留两位小数，精度给到10^-4足够
        double mid = L + (R - L) / 2.0;
        if (f(pra, L) * f(pra, mid) <= 0)
        {
            R = mid;
        }
        else
        {
            L = mid;
        }
    }
    return L;
}

void solve(vector<double> &pra)
{
    for (double i = -100; i < 100; i++)
    {
        double x1 = i, x2 = i + 1;
        double y1 = f(pra, x1), y2 = f(pra, x2);

        // 1. 如果左端点本身就是根，记录它
        if (abs(y1) < EPS)
        {
            result.push_back(x1);
        }
        // 2. 如果根在区间中间（不含两端点）
        else if (y1 * y2 < 0)
        {
            result.push_back(bisection(pra, x1, x2));
        }

        if (result.size() >= 3)
            break;
    }
}

int main()
{
    // 示例方程：x^3 - 5x^2 - 4x + 20 = 0 (根为 -2, 2, 5)
    vector<double> vec = {1, -5, -4, 20};
    solve(vec);

    sort(result.begin(), result.end());
    for (double r : result)
    {
        cout << fixed << setprecision(2) << r << " ";
    }
    return 0;
}