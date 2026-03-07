#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (n == 4)
    {
        cout << "2 4 1 3" << endl;
    }
    else
    {
        // 先输出奇数: 1, 3, 5...
        for (int i = 1; i <= n; i += 2)
        {
            cout << i << (i + 2 <= n || n % 2 == 0 ? " " : "");
        }
        // 再输出偶数: 2, 4, 6...
        for (int i = 2; i <= n; i += 2)
        {
            cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}
