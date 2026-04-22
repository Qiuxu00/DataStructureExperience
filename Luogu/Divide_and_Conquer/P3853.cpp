#include <bits/stdc++.h>
using namespace std;
int check(int mid, vector<int> &pos) // check how many pos should be launch to make every gap is smaller than mid
{
    int result = 0;
    for (int i = 0; i < pos.size() - 1; i++)
    {
        int gap = pos[i + 1] - pos[i];
        int k = gap / mid;
        double kb = (double)gap / (double)mid;
        if (kb > k)
        {
            result += k;
        }
        else
        {
            result += (k - 1);
        }
    }
    return result;
}
int get_mid(vector<int> &pos, int L, int R, int N, int K)
{
    if (L == R)
    {
        return L;
    }
    int med = (R + L) / 2;
    int c = check(med, pos);
    if (c > K)
    {
        return get_mid(pos, med + 1, R, N, K);
    }
    else
    {
        return get_mid(pos, L, med, N, K);
    }
}

int main()
{

    int L, N, K;
    cin >> L >> N >> K;
    vector<int> pos(N);
    for (int &i : pos)
    {
        cin >> i;
    }
    sort(pos.begin(), pos.end());
    cout << get_mid(pos, 1, L, N, K) << endl;
    return 0;
}