#include <iostream>
#include <cmath>
using namespace std;

int max = 0;
string s_max = "";
string Find(string str)
{
    int size = str.size();
    int i = 0, j = 0;
    for (int count = 0; count < 2 * size - 1; count++)
    {
        int left = i;
        int right = j;
        while (left >= 0 && right < size && str[left] == str[right])
        {
            if (right - left + 1 > ::max)
            {
                ::max = right - left + 1;
                s_max = str.substr(left, right - left + 1);
            }
            right++;
            left--;
        }
        i += count % 2;
        j += abs(count % 2 - 1);
    }
    return ::s_max;
}

int main()
{
    cout << Find("abadeabcbaddefc") << endl;
    return 0;
}