#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void delete_x(int x, int *arr, int length)
{
    int i(0), ii(0);
    while (ii < length)
    {
        if (arr[i] == x && ii < length)
        {
            while (ii < length && arr[ii] == x)
            {
                ii++;
            }
            if (ii < length)
            {
                swap(arr[i], arr[ii]);
            }
        }
        else
        {
            ii++;
            i++;
        }
    }
    while (i < length)
    {
        arr[i] = -1;
        i++;
    }
}

int main()
{
    int arr[] = {3, 2, 4, 1, 2, 3, 3, 3};
    delete_x(3, arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}