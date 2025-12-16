#include <iostream>
#include <list>
using namespace std;

template <typename T>
T test_01(list<T> lst, int k)
{
    auto ptr_f = lst.begin();
    auto ptr_s = lst.begin();
    for (int i = 0; i < k; i++)
    {
        ptr_f++;
    }
    while (ptr_f != end(lst))
    {
        ptr_f++;
        ptr_s++;
    }
    return *ptr_s;
}

int main()
{
    int size = 10;
    int k = 3;
    list<int> lst;
    for (int i = 0; i < size; i++)
    {
        lst.push_back(i);
    }

    cout << "The k_th to the last is " << test_01(lst, k) << endl;
    return 0;
}