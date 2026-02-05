#include <iostream>
#include <vector>
using namespace std;

void Quick_choose_k(vector<int> &vec, int L, int R, int K)
{
    if (L >= R)
    {
        return;
    }
    int left = L;
    int right = R;
    while (L != R)
    {
        while (vec[R] >= vec[left] && L < R)
        {
            R--;
        }
        while (vec[L] <= vec[left] && L < R)
        {
            L++;
        }
        if (L < R)
        {
            swap(vec[L], vec[R]);
        }
    }
    if (L == R)
    {
        swap(vec[left], vec[L]);
    }
    if (K <= L - 1)
    {
        Quick_choose_k(vec, left, R - 1, K);
    }
    if (K >= L + 1)
    {
        Quick_choose_k(vec, L + 1, right, K);
    }
}
int main()
{
    vector<int> test = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    for (auto i : test)
    {
        cout << i << " ";
    }
    int k = 6;
    cout << endl
         << "结果: " << endl;
    Quick_choose_k(test, 0, test.size() - 1, k);
    cout << test[k - 1] << endl;
    return 0;
}