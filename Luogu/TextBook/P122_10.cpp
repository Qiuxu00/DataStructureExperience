#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> c_1 = {{1, 5}, {6, 8}, {12, 15}, {16, 20}, {22, 25}, {30, 35}, {38, 42}, {45, 50}, {52, 57}, {60, 65}, {68, 72}, {75, 80}, {82, 85}, {88, 92}, {95, 100}};
    vector<pair<int, int>> c_2 = {{2, 4}, {5, 7}, {9, 13}, {14, 17}, {18, 23}, {24, 28}, {29, 32}, {34, 39}, {40, 44}, {46, 51}, {53, 58}, {61, 66}, {67, 70}, {71, 76}, {78, 83}};
    vector<pair<int, int>> result;
    int ptr_1 = 0;
    int ptr_2 = 0;
    int tlb = 0;
    while (ptr_1 < c_1.size() && ptr_2 < c_2.size())
    {
        if (c_1[ptr_1].second <= c_2[ptr_2].second)
        {
            result.push_back(c_1[ptr_1]);
            tlb = c_1[ptr_1++].second;
            while (ptr_2 < c_2.size() && c_2[ptr_2].first < tlb)
            {
                ptr_2++;
            }
        }
        else
        {
            result.push_back(c_2[ptr_2]);
            tlb = c_2[ptr_2++].second;
            while (ptr_1 < c_1.size() && c_1[ptr_1].first < tlb)
            {
                ptr_1++;
            }
        }
    }
    if (ptr_1 < c_1.size())
    {
        while (ptr_1 < c_1.size())
        {
            if (c_1[ptr_1].first >= tlb)
            {
                result.push_back(c_1[ptr_1]);
            }
            ptr_1++;
        }
    }
    if (ptr_2 < c_2.size())
    {
        while (ptr_2 < c_2.size())
        {
            if (c_2[ptr_2].first >= tlb)
            {
                result.push_back(c_2[ptr_2]);
            }
            ptr_2++;
        }
    }
    cout << "Nums:" << result.size() << endl;
    for (auto i : result)
    {
        cout << "(" << i.first << "," << i.second << ") ";
    }
    cout << endl;
    return 0;
}