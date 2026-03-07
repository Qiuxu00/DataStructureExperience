#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &pos, int op, int side, int bottom = 0, int edge = 0, vector<int> nums = {})
{
    vector<vector<char>> final(side, vector<char>(side));
    if (op == 0)
    {
        int pre = 0;
        for (int i = 0; i < 3; i++)
        {
            int length = (pos[2 * i] == side ? pos[2 * i + 1] : pos[2 * i]);
            for (int ii = 0; ii < length; ii++)
            {
                for (int row = 0; row < side; row++)
                {
                    final[row][ii + pre] = 'A' + i;
                }
            }
            pre += length;
        }
        for (auto i : final)
        {
            for (auto ii : i)
            {
                cout << ii << " ";
            }
            cout << endl;
        }
    }
    if (op == 1)
    {
        int pre = bottom;
        for (int i = 0; i < bottom; i++)
        {
            for (int row = 0; row < side; row++)
            {
                final[row][i] = 'A' + nums[0];
            }
        }
        for (int i = bottom; i < side; i++)
        {
            for (int row = 0; row < edge; row++)
            {
                final[row][i] = 'A' + nums[1];
            }
        }
        for (int i = bottom; i < side; i++)
        {
            for (int row = edge; row < side; row++)
            {
                final[row][i] = 'A' + nums[2];
            }
        }
        for (auto i : final)
        {
            for (auto ii : i)
            {
                cout << ii << " ";
            }
            cout << endl;
        }
    }
}

void tl(vector<int> &pos)
{
    bool flag = true;
    // case:A-B-C
    int max_pos_l = 0;
    int max_pos;
    for (int i = 0; i < 6; i++)
    {
        if (pos[i] > max_pos_l)
        {
            max_pos_l = pos[i];
            max_pos = i;
        }
    }
    // case:A-B-C
    int nums = 0;
    int ano_side = 0;
    for (int i = 0; i < 3; i++)
    {
        if (pos[2 * i] == pos[max_pos] || pos[2 * i + 1] == pos[max_pos])
        {
            nums++;
            ano_side += (pos[2 * i] == pos[max_pos] ? pos[2 * i + 1] : pos[2 * i]);
        }
    }
    if (nums != 3 || ano_side != pos[max_pos])
    {
        flag = false;
    }
    else
    {
        print(pos, 0, pos[max_pos]);
        return;
    }
    // A - (B, C)
    int bottom;
    vector<int> num;
    if (max_pos % 2 == 0)
    {
        bottom = pos[max_pos + 1];
    }
    else
    {
        bottom = pos[max_pos - 1];
    }

    for (int i = 0; i < 3; i++)
    {
        if (i != max_pos / 2)
        {
            num.push_back(i);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int ii = 0; ii < 2; ii++)
        {
            if (pos[2 * num[0] + i] == pos[2 * num[1] + ii])
            {
                int side_s = pos[2 * num[0] + i];
                int side_l = 0;
                side_l += (i == 0 ? pos[2 * num[0] + 1] : pos[2 * num[0]]);
                int edge = side_l;
                side_l += (ii == 0 ? pos[2 * num[1] + 1] : pos[2 * num[1]]);
                if (side_l == pos[max_pos] && (side_s + bottom) == pos[max_pos])
                {

                    print(pos, 1, pos[max_pos], bottom, edge, {max_pos / 2, num[0], num[1]});
                    return;
                }
            }
        }
    }

    cout << "No Solution" << endl;
}

int main()
{
    vector<int> pos = {10, 4, 6, 8, 6, 3};
    tl(pos);
    return 0;
}