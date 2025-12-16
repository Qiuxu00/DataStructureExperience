#include <iostream>
using namespace std;

void compare(int arr_0[], int arr_1[], int size_a, int size_b)
{

    int min = size_a > size_b ? size_b : size_a;
    int count = 0;
    for (; count < min; count++)
    {
        if (arr_0[count] > arr_1[count])
        {
            cout << "a>b" << endl;
            return;
        }
        else if (arr_0[count] < arr_1[count])
        {
            cout << "a<b" << endl;
            return;
        }
    }
    if (count == min)
    {
        if (size_a > size_b)
        {
            cout << "a>b" << endl;
        }
        else if (size_a < size_b)
        {
            cout << "a<b" << endl;
        }
        else
        {
            cout << "a=b" << endl;
        }
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {1, 2};
    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);
    compare(a, b, size_a, size_b);
    return 0;
}