#include <iostream>
#include <vector>
using namespace std;

void Quick_sort(vector<int> &vec, int L, int R)
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
    Quick_sort(vec, left, L - 1);
    Quick_sort(vec, L + 1, right);
}

int main()
{
    vector<int> test = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    for (auto i : test)
    {
        cout << i << " ";
    }
    cout << endl
         << "快排之后: " << endl;
    Quick_sort(test, 0, test.size() - 1);
    for (auto i : test)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}