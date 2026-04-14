#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> heads = {5, 4};
    vector<int> z = {7, 8, 4};
    int ptr_h = 0;
    int ptr_z = 0;
    int result = 0;
    sort(heads.begin(), heads.end());
    sort(z.begin(), z.end());
    for (; ptr_z < z.size(); ptr_z++)
    {
        if (z[ptr_z] >= heads[ptr_h])
        {
            result += z[ptr_z];
            ptr_h++;
        }
    }
    if (ptr_h != heads.size())
    {
        cout << "you died!" << endl;
        return 0;
    }
    cout << result << endl;
    return 0;
}