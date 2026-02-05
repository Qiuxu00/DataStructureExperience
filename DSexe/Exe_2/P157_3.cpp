#include <iostream>
#include <vector>
using namespace std;

bool is_ok(int x, int y, int n, vector<vector<int>> *Matrix)
{
    if (x >= 0 && x < n && y >= 0 && y < n && (*Matrix)[x][y] == 0)
    {
        return true;
    }
    return false;
}

bool Path(vector<vector<int>> *Matrix, int x = 0, int y = 0, int n = 0)
{
    (*Matrix)[x][y] = 2;
    if (x == n - 1 && y == n - 1)
    {
        return 1;
    }
    if (!(is_ok(x - 1, y, n, Matrix) || is_ok(x - 1, y - 1, n, Matrix) || is_ok(x, y - 1, n, Matrix) || is_ok(x + 1, y - 1, n, Matrix) || is_ok(x + 1, y, n, Matrix) || is_ok(x + 1, y + 1, n, Matrix) || is_ok(x, y + 1, n, Matrix) || is_ok(x - 1, y + 1, n, Matrix)))
    {
        (*Matrix)[x][y] = 3;
        return 0;
    }
    if (is_ok(x - 1, y, n, Matrix) && Path(Matrix, x - 1, y, n))
    {
        return true;
    }
    else if (is_ok(x - 1, y - 1, n, Matrix) && Path(Matrix, x - 1, y - 1, n))
    {
        return 1;
    }
    else if (is_ok(x + 1, y - 1, n, Matrix) && Path(Matrix, x + 1, y - 1, n))
    {
        return 1;
    }
    else if (is_ok(x + 1, y, n, Matrix) && Path(Matrix, x + 1, y, n))
    {
        return 1;
    }
    else if (is_ok(x, y - 1, n, Matrix) && Path(Matrix, x, y - 1, n))
    {
        return 1;
    }
    else if (is_ok(x + 1, y + 1, n, Matrix) && Path(Matrix, x + 1, y + 1, n))
    {
        return 1;
    }
    else if (is_ok(x, y + 1, n, Matrix) && Path(Matrix, x, y + 1, n))
    {
        return 1;
    }
    else if (is_ok(x - 1, y + 1, n, Matrix) && Path(Matrix, x - 1, y + 1, n))
    {
        return 1;
    }
    (*Matrix)[x][y] = 3;
    return 0;
}

int main()
{

    vector<vector<int>> Matrix = {
        {0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 1, 1, 0}};
    if (Path(&Matrix, 0, 0, 9))
    {
        for (vector<int> v : Matrix)
        {
            for (int i : v)
            {
                if (i == 3)
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}