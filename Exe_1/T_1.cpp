#include <iostream>
#include <cmath>
using namespace std;

template <class T>
int func(T arr[], int L, int R, T val)
{

    if (arr[(L + R) / 2] == val)
    {
        return (L + R) / 2;
    }
    else if (L == R - 1)
    {
        if (val < arr[L])
        {
            return L;
        }
        if (val > arr[R])
        {
            return R + 1;
        }
        return L + 1;
    }

    if (arr[(L + R) / 2] > val)
    {
        return func(arr, L, (L + R) / 2, val);
    }
    else if (arr[(L + R) / 2] < val)
    {
        return func(arr, (L + R) / 2, R, val);
    }
    return NAN;
}

int main()
{
    double arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << func(arr, 0, sizeof(arr) / sizeof(arr[0]), 2.0) << endl;

    return 0;
}