#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M, N, K, L, D;
    cin >> M >> N >> K >> L >> D;
    vector<vector<int>> couple(D, vector<int>(4));
    for (auto &v : couple)
    {
        for (int &i : v)
        {
            cin >> i;
        }
    }

    map<int, int> xy;
    map<int, int> yx;

    for (auto i : couple)
    {
        if (i[0] == i[2])
        {
            if (i[1] > i[3])
            {
                xy[i[3]]++;
            }
            else
            {
                xy[i[1]]++;
            }
        }
        else
        {
            if (i[0] <= i[2])
            {
                yx[i[0]]++;
            }
            else
            {
                yx[i[2]]++;
            }
        }
    }
    for (int i = 1; i < N; i++)
    {
        xy[i]++;
    }
    for (int i = 1; i < M; i++)
    {
        yx[i]++;
    }
    vector<pair<int, int>> XY;
    vector<pair<int, int>> YX;
    for (auto i : xy)
    {
        XY.push_back({i.second, i.first});
    }
    for (auto i : yx)
    {
        YX.push_back({i.second, i.first});
    }
    sort(XY.begin(), XY.end(), greater<pair<int, int>>());
    sort(YX.begin(), YX.end(), greater<pair<int, int>>());

    vector<int> result_L;
    vector<int> result_K;

    // 2. 取前 L 个纵向通道的“编号”
    for (int i = 0; i < L && i < XY.size(); i++)
    {
        result_L.push_back(XY[i].second);
    }
    // 3. 取前 K 个横向通道的“编号”
    for (int i = 0; i < K && i < YX.size(); i++)
    {
        result_K.push_back(YX[i].second);
    }

    sort(result_L.begin(), result_L.end());
    sort(result_K.begin(), result_K.end());
    for (int i = 0; i < result_K.size(); i++)
    {
        cout << result_K[i] << (i == result_K.size() - 1 ? "" : " ");
    }
    cout << endl;

    for (int i = 0; i < result_L.size(); i++)
    {
        cout << result_L[i] << (i == result_L.size() - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
}