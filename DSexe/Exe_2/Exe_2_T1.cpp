#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> *Counter(string str)
{
    unordered_map<char, int> *map_result = new unordered_map<char, int>;
    for (char i : str)
    {
        (*map_result)[i]++;
    }
    return map_result;
}

int main()
{
    for (pair<char, int> i : *Counter("aaggceufeuhsxcsfggbb"))
    {
        cout << i.first << " " << i.second << "times" << endl;
    }
    return 0;
}