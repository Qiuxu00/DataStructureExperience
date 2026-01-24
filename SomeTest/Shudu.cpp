#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 状态存储：行、列、九宫格各用一个9位二进制数记录数字占用情况
int row[9], col[9], box[9];
int board[9][9];
bool solved = false;

// 获取九宫格索引
inline int getBox(int r, int c)
{
    return (r / 3) * 3 + (c / 3);
}

// 在 (r, c) 位置填入或移除数字 n
void flip(int r, int c, int n)
{
    row[r] ^= (1 << n);
    col[c] ^= (1 << n);
    box[getBox(r, c)] ^= (1 << n);
}

void dfs(const vector<pair<int, int>> &spaces, int pos)
{
    if (pos == spaces.size())
    {
        solved = true;
        return;
    }

    int r = spaces[pos].first;
    int c = spaces[pos].second;

    // 定量分析：获取当前格所有可选数字的掩码 (1代表可选)
    // 0x1FF 即二进制 111111111 (9位)
    int mask = ~(row[r] | col[c] | box[getBox(r, c)]) & 0x1FF;

    // 尝试填入每一个可选数字
    for (int n = 0; n < 9; ++n)
    {
        if ((mask >> n) & 1)
        {
            flip(r, c, n);
            board[r][c] = n + 1;
            dfs(spaces, pos + 1);
            if (solved)
                return;
            // 回溯：利用双向操作恢复状态
            flip(r, c, n);
        }
    }
}

void solveSudoku(vector<vector<char>> &boardIn)
{
    vector<pair<int, int>> spaces;
    // 初始化状态
    for (int i = 0; i < 9; ++i)
        row[i] = col[i] = box[i] = 0;
    solved = false;

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (boardIn[i][j] == '.')
            {
                spaces.push_back({i, j});
            }
            else
            {
                int n = boardIn[i][j] - '1';
                flip(i, j, n);
                board[i][j] = n + 1;
            }
        }
    }

    dfs(spaces, 0);

    // 将结果写回原容器
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            boardIn[i][j] = board[i][j] + '0';
        }
    }
}

int main()
{
    // 示例盘面
    vector<vector<char>> b = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '0', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(b);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}