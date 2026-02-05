#include <iostream>
#include <vector>
using namespace std;

int fre = 0;
vector<int> Result;
void merge_e(vector<int> &test, vector<int> &result, int L, int R)
{
    if (L >= R)
    {
        return;
    }
    merge_e(test, result, L, (L + R) / 2);
    merge_e(test, result, (L + R) / 2 + 1, R);
    int i = L;
    int ii = (L + R) / 2 + 1;
    int cur = L;
    while (i <= (L + R) / 2 && ii <= R)
    {
        if (test[ii] >= test[i])
        {
            result[cur] = test[i];
            i++;
            cur++;
        }
        else if (test[ii] < test[i])
        {
            result[cur] = test[ii];
            ii++;
            cur++;
            fre += ((L + R) / 2 - i + 1);
        }
    }

    while (i <= (L + R) / 2)
    {
        result[cur] = test[i];
        i++;
        cur++;
    }

    while (ii <= R)
    {
        result[cur] = test[ii];
        ii++;
        cur++;
    }
    for (int i = L; i <= R; i++)
    {
        test[i] = result[i];
    }
}

int merge(vector<int> &test)
{
    Result.resize(test.size());
    merge_e(test, Result, 0, test.size() - 1);
}

int main()
{
    vector<int> arr = {4, 9, 2, 1, 10, 5, 8, 3, 7, 6};
    merge(arr);
    cout << "逆序对数量: " << fre << endl; // 输出 21
    return 0;
}