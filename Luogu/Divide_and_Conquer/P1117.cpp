#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void QSr(vector<int> &vec, int L, int R)
{
    if (L >= R)
        return;

    // 随机化基准，防止有序数据退化
    int randomIndex = L + rand() % (R - L + 1);
    swap(vec[L], vec[randomIndex]);

    int pivot = vec[L];

    // 三路划分核心变量
    int lt = L;    // [L+1, lt] 区域小于 pivot
    int gt = R;    // [gt, R] 区域大于 pivot
    int i = L + 1; // 当前扫描指针

    while (i <= gt)
    {
        if (vec[i] < pivot)
        {
            swap(vec[i], vec[lt]);
            lt++;
            i++;
        }
        else if (vec[i] > pivot)
        {
            swap(vec[i], vec[gt]);
            gt--;
            // 注意这里 i 不加 1，因为交换过来的 vec[gt] 还需要继续判断
        }
        else
        {
            i++; // 等于 pivot 的情况，直接跳过
        }
    }

    // 此时 [L, lt-1] < pivot, [lt, gt] == pivot, [gt+1, R] > pivot
    QSr(vec, L, lt - 1);
    QSr(vec, gt + 1, R);
}

int main()
{
    // 提速：关闭同步流
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    srand(time(NULL));
    QSr(vec, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}