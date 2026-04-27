#include <bits/stdc++.h>
using namespace std;

struct BigInt
{
    vector<int> digits;

    BigInt(long long v = 0)
    {
        if (v == 0)
            digits.push_back(0);
        while (v > 0)
        {
            digits.push_back(v % 10);
            v /= 10;
        }
    }

    BigInt(string s)
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            digits.push_back(s[i] - '0');
        }
        if (digits.empty())
            digits.push_back(0);
    }

    bool operator>(const BigInt &b) const
    {
        if (digits.size() != b.digits.size())
            return digits.size() > b.digits.size();
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] != b.digits[i])
                return digits[i] > b.digits[i];
        }
        return false;
    }

    BigInt operator*(const BigInt &b) const
    {
        BigInt res;
        res.digits.resize(digits.size() + b.digits.size(), 0);
        for (int i = 0; i < digits.size(); i++)
        {
            int carry = 0;
            for (int j = 0; j < b.digits.size() || carry; j++)
            {
                long long cur = res.digits[i + j] +
                                digits[i] * 1LL * (j < b.digits.size() ? b.digits[j] : 0) + carry;
                res.digits[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        while (res.digits.size() > 1 && res.digits.back() == 0)
            res.digits.pop_back();
        return res;
    }

    void print()
    {
        for (int i = digits.size() - 1; i >= 0; i--)
            cout << digits[i];
        cout << endl;
    }
};

void solve()
{
    int N;
    int K;
    string S;
    cin >> N >> K >> S;
    vector<vector<BigInt>> dp(K + 1, vector<BigInt>(N));
    vector<vector<BigInt>> subStr(N, vector<BigInt>(N, BigInt(0)));
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            subStr[i][j] = BigInt(S.substr(i, j - i + 1));
        }
    }
    for (int i = 0; i < N; i++)
    {
        dp[0][i] = subStr[0][i];
    }
    for (int i = 1; i <= K; i++)
    {
        for (int j = i; j < N; j++)
        {
            BigInt max_ = dp[i - 1][j - 1] * subStr[j][j];
            for (int k = i; k < j; k++)
            {
                BigInt temp = dp[i - 1][k - 1] * subStr[k][j];
                if (temp > max_)
                {
                    max_ = temp;
                }
            }
            dp[i][j] = max_;
        }
    }
    dp[K][N - 1].print();
}
int main()
{
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {

        solve();
    }

    return 0;
}