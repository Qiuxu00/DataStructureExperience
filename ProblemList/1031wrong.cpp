#include <bits/stdc++.h>
using namespace std;

double limit = 1e-10;

struct node
{
    double x;
    double y;
};

double get_x(node &N, double d)
{
    return N.x + sqrt(pow(d, 2) - pow(N.y, 2));
}

bool is_in(double r_x, node &judge, double d) //(r_x,0)(j.x,j.y)
{
    return ((r_x - judge.x) * (r_x - judge.x) + (judge.y) * (judge.y) - d * d <= limit);
}

void solve(vector<int> &res)
{
    int n, d;
    cin >> n >> d;
    vector<node> Nodes(n);
    for (auto &n : Nodes)
    {
        cin >> n.x >> n.y;
    }
    sort(Nodes.begin(), Nodes.end(), [](node &n1, node &n2)
         { return n1.x < n2.x; });
    int ptr = 0;
    int result = 0;
    while (ptr < n)
    {
        result++;
        double r_x = get_x(Nodes[ptr], d);
        while (is_in(r_x, Nodes[ptr], d) && ptr < n)
        {
            ptr++;
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