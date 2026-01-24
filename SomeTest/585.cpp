#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void LT(vector<int> &arr, int k, vector<int> &lst)
{

    vector<int> WIN(k); // 此节点胜者的下标
    for (int i = k - 1; i > 0; i--)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int p1 = (left >= k) ? (left - k) : WIN[left];
        int p2 = (right >= k) ? (right - k) : WIN[right]; // 比较者
        if (arr[p1] <= arr[p2])
        {
            lst[i] = p2;
            WIN[i] = p1;
        }
        else
        {
            lst[i] = p1;
            WIN[i] = p2;
        }
    }
    lst[0] = (k == 1) ? 0 : WIN[1];
}

int main()
{
    vector<int> arr = {2, 5, 6, 1, 3, 4};
    int k = arr.size();
    vector<int> lst(k);
    LT(arr, k, lst);
    cout << "第 " << lst[0] << " 是胜者" << endl;
    return 0;
}