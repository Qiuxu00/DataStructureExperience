#include <bits/stdc++.h>
using namespace std;
void Find_(vector<vector<int>> &map, vector<vector<int>> &visited, int row, int col)
{
    visited[row][col] = 1;
    if (row - 1 >= 0 && map[row - 1][col] == 1 && visited[row - 1][col] == 0)
    {
        Find_(map, visited, row - 1, col);
    }
    if (row + 1 < map.size() && map[row + 1][col] == 1 && visited[row + 1][col] == 0)
    {
        Find_(map, visited, row + 1, col);
    }
    if (col + 1 < map[0].size() && map[row][col + 1] == 1 && visited[row][col + 1] == 0)
    {
        Find_(map, visited, row, col + 1);
    }
    if (col - 1 >= 0 && map[row][col - 1] == 1 && visited[row][col - 1] == 0)
    {
        Find_(map, visited, row, col - 1);
    }
    return;
}
int is(vector<vector<int>> &map)
{
    int result = 0;
    vector<vector<int>> visited(map.size(), vector<int>(map[0].size()));
    for (int row = 0; row < map.size(); row++)
    {
        for (int col = 0; col < map[0].size(); col++)
        {
            if (map[row][col] == 1 && visited[row][col] == 0)
            {
                Find_(map, visited, row, col);
                result++;
            }
        }
    }
    return result;
}

int main()
{
    int r = 5;
    int c = 5;
    vector<vector<int>> map(r, vector<int>(c));
    map = {{1, 1, 0, 0, 0}, {0, 1, 0, 1, 1}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 1, 1}};
    cout << is(map) << endl;
    return 0;
}