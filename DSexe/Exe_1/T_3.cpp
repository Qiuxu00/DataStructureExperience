#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Triple
{
    int row;
    int col;
    int val;
};

class SparseMatrix
{
public:
    int row;
    int col;
    int terms;
    Triple *smArray;
    SparseMatrix(int r, int c, int t) : row(r), col(c), terms(t)
    {
        smArray = new Triple[terms];
    }
    SparseMatrix *fastTranspose();
    void Print() const
    {
        for (int i = 0; i < terms; i++)
        {
            cout << "(" << smArray[i].row << ", "
                 << smArray[i].col << ", "
                 << smArray[i].val << ")\n";
        }
    }
    ~SparseMatrix()
    {
    }
};

SparseMatrix *SparseMatrix::fastTranspose()
{
    SparseMatrix *result = new SparseMatrix(col, row, terms);
    vector<vector<int>> assist(2, vector<int>(col, 0)); // 创建二维的vector数组，作为辅助数组存放位置关系
    for (int i = 0; i < terms; i++)
    {
        assist[0][smArray[i].col]++; // 计算每一列的个数
    }
    assist[1][0] = 0;
    for (int i = 1; i < col; i++)
    {
        assist[1][i] = assist[1][i - 1] + assist[0][i - 1]; // 计算开始值
    }
    for (int i = 0; i < terms; i++)
    {
        int start = assist[1][this->smArray[i].col];       // 由于原数组按行数顺序，所以可以直接在下面加加实现偏移
        result->smArray[start].row = this->smArray[i].col; // 理清楚关系
        result->smArray[start].col = this->smArray[i].row;
        result->smArray[start].val = this->smArray[i].val;
        assist[1][this->smArray[i].col]++; // 偏移
    }

    return result;
}

int main()
{

    SparseMatrix a(10, 20, 5);
    a.smArray[0] = {1, 3, 7};
    a.smArray[1] = {3, 0, 5};
    a.smArray[2] = {6, 14, 2};
    a.smArray[3] = {6, 15, 9};
    a.smArray[4] = {9, 11, 1};
    a.Print();

    a.fastTranspose()->Print();

    return 0;
}