#include <bits/stdc++.h>
using namespace std;

void get_1(vector<int> &vec, vector<int> &B, vector<int> &S, vector<int> &left_v, vector<int> &right_v)
{

    int result = S[0] - B[0];
    vec[0] = result;
    int left = 0;
    int right = 0;
    int temple_left = 0;
    for (int i = 1; i < B.size(); i++)
    {
        if (B[i] <= B[temple_left])
        {
            temple_left = i;
        }
        if (S[i] - B[temple_left] > result)
        {
            right = i;
            left = temple_left;
            result = S[right] - B[left];
        }
        vec[i] = result;
        left_v[i] = left;
        right_v[i] = right;
    }
}

void get_2(vector<int> &vec, vector<int> &B, vector<int> &S, vector<int> &left_v, vector<int> &right_v)
{
    int n = B.size();
    int result = S[n - 1] - B[n - 1];
    vec[n - 1] = result;
    int left = n - 1;
    int right = n - 1;
    int temple_right = n - 1;
    left_v[n - 1] = left;
    right_v[n - 1] = right;
    for (int i = n - 2; i >= 0; i--)
    {
        if (S[i] > S[temple_right])
        {
            temple_right = i;
        }
        if (S[temple_right] - B[i] > result)
        {
            right = temple_right;
            left = i;
            result = S[temple_right] - B[i];
        }
        vec[i] = result;
        left_v[i] = left;
        right_v[i] = right;
    }
}

int main()
{
    vector<int> B = {5, 10, 3, 8, 1, 6};
    vector<int> S = {2, 9, 1, 7, 0, 5};
    vector<int> first_left(B.size());
    vector<int> first_right(B.size());
    vector<int> second_left(B.size());
    vector<int> second_right(B.size());
    vector<int> left(B.size());
    vector<int> right(B.size());
    get_1(left, B, S, first_left, first_right);
    get_2(right, B, S, second_left, second_right);
    int fl = first_left[0];
    int fr = first_right[0];
    int sl = second_left[0];
    int sr = second_right[0];
    int max_ = left[0] + right[0];
    for (int k = 1; k < B.size(); k++)
    {
        if (left[k] + right[k] > max_)
        {
            max_ = left[k] + right[k];
            fl = first_left[k];
            fr = first_right[k];
            sl = second_left[k];
            sr = second_right[k];
        }
    }
    cout << "The result is " << max_ << endl
         << "The first pair is " << fl + 1 << " " << fr + 1 << endl
         << "The second pair is " << sl + 1 << " " << sr + 1 << endl;
    return 0;
}