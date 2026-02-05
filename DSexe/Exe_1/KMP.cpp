#include <iostream>
#include <string>
using namespace std;

// 两组一样的子串，在下一次match的时候可以直接跳过
// next数组的本质，就是在寻找相同前后缀的长度，并且一定是最长的前后缀
// 前后缀的针对整个截取到的字串而言的，比如next的第一个数的大小，取决于在字串中截取到第一个字符的那个子串的子串的相同的前后缀的字符个数
// ababc，就是00120

#include <iostream>
#include <string>
using namespace std;

// 计算模式串的 next 数组（也称为 lps 数组）
// 参数：
//   pattern —— 模式串（子串）
//   next —— 用来保存每个位置对应的最长相等前后缀长度
void build_next(const string &pattern, int next[]) // 前后缀求解方法
{
    int m = pattern.size();
    next[0] = 0; // 第一个字符的前后缀长度一定是0
    int j = 0;   // j表示当前已匹配的“最长前缀”的长度，同时，j也代表了模式串中开始重新匹配的位置

    // 从第二个字符开始（i从1）
    for (int i = 1; i < m; i++)
    {
        // 如果当前字符不匹配，就回退 j 到前一个可用的位置
        // 不断尝试更短的前缀
        while (j > 0 && pattern[i] != pattern[j]) // 这个循环实现的是不断找短前缀
        {
            j = next[j - 1]; // 直到零停止
        }

        // 如果当前字符匹配，最长前缀长度 +1
        if (pattern[i] == pattern[j]) // 等于的时候才+1，也就是说，一直不等于的时候，是不会++的，j一直是0，永远都是从第0个字符开始比较
        {
            j++; // 计算长度要加加
        }

        // 记录当前位置的最长相等前后缀长度
        next[i] = j;
    }
}

int KMP_match(string str_0, string str_1)
{
    int size = str_1.size();
    int *next = new int[size]{0};
    build_next(str_1, next);

    int ptr_0(0), ptr_1(0); // 大家都是从0开始匹配

    while (ptr_0 < str_0.length())
    {
        if (str_0[ptr_0] == str_1[ptr_1] && ptr_1 != size - 1)
        {
            ptr_0++;
            ptr_1++; // 上下相等的时候直接直接都向后移
        }
        else if (str_0[ptr_0] == str_1[ptr_1] && ptr_1 == size - 1) // 如果模式串的最后一位对上了就直接返回位置即可
        {
            return ptr_0 - ptr_1;
        }
        else
        {
            if (ptr_1 > 0)
            {
                ptr_1 = next[ptr_1 - 1]; // 大于零的时候，说明可以跳过模式串了，由于不一样的那一位之前，模式串和主串的前后缀是一样的，所以可以直接让主串那个不一样的字符前面的后缀，和模式串前面的前缀对上，就不需要比较前缀了，因为前后缀相同
            }
            else
            {
                ptr_0++; // ptr_1还等于0的时候发现不匹配，直接让主串向后移一个单位
            }
        }
    }
    return -1;
}

int main()
{
    string str_0("abababcaaa");
    string str_1("ababc");
    cout << KMP_match(str_0, str_1) << endl;

    return 0;
}