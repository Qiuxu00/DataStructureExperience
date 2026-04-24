#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M;
    cin >> M;
    vector<int> size(M);
    vector<int> K(M);
    vector<string> vec(M);
    for (int i = 0; i < M; i++)
    {
        cin >> size[i];
        cin >> K[i];
        for (int j = 0; j < size[i]; j++)
        {
            cin >> vec[i];
        }
    }
    return 0;
}