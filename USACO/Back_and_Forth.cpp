#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 使用 set 自动存储所有可能的最终读数并去重
set<int> possible_readings;

/**
 * 递归搜索函数
 * @param day   当前是第几天（从周二 2 到周五 5）
 * @param tank1 第一个奶棚当前的牛奶量
 * @param b1    第一个奶棚当前的桶列表
 * @param b2    第二个奶棚当前的桶列表
 */
void solve(int day, int tank1, vector<int> b1, vector<int> b2)
{
    // 递归出口：周五的运送完成后（进入所谓的“周六”状态）
    if (day == 6)
    {
        possible_readings.insert(tank1);
        return;
    }

    // 周二和周四：从 Barn 1 运往 Barn 2
    if (day % 2 == 0)
    {
        for (int i = 0; i < b1.size(); ++i)
        {
            int bucket_size = b1[i];

            // 模拟运送过程：创建新的桶列表，传递给下一层
            vector<int> next_b1 = b1;
            next_b1.erase(next_b1.begin() + i); // 从 Barn 1 拿走

            vector<int> next_b2 = b2;
            next_b2.push_back(bucket_size); // 送到 Barn 2

            solve(day + 1, tank1 - bucket_size, next_b1, next_b2);
        }
    }
    // 周三和周五：从 Barn 2 运往 Barn 1
    else
    {
        for (int i = 0; i < b2.size(); ++i)
        {
            int bucket_size = b2[i];

            vector<int> next_b2 = b2;
            next_b2.erase(next_b2.begin() + i); // 从 Barn 2 拿走

            vector<int> next_b1 = b1;
            next_b1.push_back(bucket_size); // 送到 Barn 1

            solve(day + 1, tank1 + bucket_size, next_b1, next_b2);
        }
    }
}

int main()
{
    vector<int> initial_b1(10), initial_b2(10);

    // 输入第一个奶棚的 10 个桶
    for (int i = 0; i < 10; ++i)
        cin >> initial_b1[i];
    // 输入第二个奶棚的 10 个桶
    for (int i = 0; i < 10; ++i)
        cin >> initial_b2[i];

    // 从周二开始递归，初始奶量为 1000
    solve(2, 1000, initial_b1, initial_b2);

    // 输出 set 中存储的不同读数的数量
    cout << possible_readings.size() << endl;

    return 0;
}