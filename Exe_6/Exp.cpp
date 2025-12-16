#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

class Union_set
{
public:
    vector<int> parent;
    Union_set(int n = 26)
    {
        parent.resize(n);
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }
    }
    int find_p(int v)
    {

        return v == parent[v] ? v : parent[v] = find_p(parent[v]);
    }
    void unite(int v, int n)
    {
        parent[find_p(v)] = find_p(n);
    }
    bool is_connect(int v, int n)
    {

        return find_p(v) == find_p(n);
    }
};

bool IS_correct(vector<string> *equation)
{
    Union_set set_equ;
    for (auto i : *equation)
    {
        if (i[1] == '=')
        {
            set_equ.unite(int(i[0]) - 97, int(i[3]) - 97);
        }
    }
    for (auto i : *equation)
    {
        if (i[1] == '!')
        {
            if (set_equ.is_connect(int(i[0]) - 97, int(i[3]) - 97))
            {
                return false;
            }
        }
    }
    return true;
}

// --- 浠ヤ笅鏄�鐢熸垚鐨勬祴璇曚唬鐮� ---

void run_test(int id, vector<string> equations, bool expected)
{
    cout << "Test Case " << id << ": ";

    // 鎵撳嵃鏂圭▼缁�
    cout << "{ ";
    for (size_t i = 0; i < equations.size(); ++i)
    {
        cout << "\"" << equations[i] << "\"";
        if (i < equations.size() - 1)
            cout << ", ";
    }
    cout << " }";

    // 璋冪敤浣犵殑鍑芥暟 (娉ㄦ剰锛氬洜涓轰綘鐨勫嚱鏁版帴鏀舵寚閽堬紝鎵€浠ヨ繖閲岃�佸姞 &)
    bool result = IS_correct(&equations);

    // 鎵撳嵃缁撴灉
    cout << "\n   -> Result: " << (result ? "True" : "False");
    cout << " (Expected: " << (expected ? "True" : "False") << ")";

    if (result == expected)
    {
        cout << " 鉁� PASS" << endl;
    }
    else
    {
        cout << " 鉂� FAIL" << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

int main()
{
    cout << "--- Starting Equations Possible Tests ---" << endl
         << endl;

    // 娴嬭瘯鐢ㄤ緥 1: 绠€鍗曠殑鐭涚浘 (a绛変簬b锛屼絾a涓嶇瓑浜巄)
    // 棰勬湡锛欶alse
    run_test(1, {"a==b", "b!=a"}, false);

    // 娴嬭瘯鐢ㄤ緥 2: 绠€鍗曠殑杩為€� (b绛変簬a锛宎绛変簬b)
    // 棰勬湡锛歍rue
    run_test(2, {"b==a", "a==b"}, true);

    // 娴嬭瘯鐢ㄤ緥 3: 浼犻€掓€х煕鐩� (a=b, b=c -> a=c锛屼絾棰樼洰璇� a!=c)
    // 棰勬湡锛欶alse
    run_test(3, {"a==b", "b==c", "a!=c"}, false);

    // 娴嬭瘯鐢ㄤ緥 4: 澶嶆潅鐨勬�ｇ‘鎯呭喌 (a=b, b=d, c=c)
    // 棰勬湡锛歍rue
    run_test(4, {"c==c", "b==d", "x!=z"}, true);

    // 娴嬭瘯鐢ㄤ緥 5: 绋嶅�嶆潅鐨勪紶閫掗摼鐭涚浘
    // (a=b, b=c, c=d, d=e -> 鍏ㄦ槸涓€瀹朵汉锛屾渶鍚庢潵涓� e!=a)
    // 棰勬湡锛欶alse
    run_test(5, {"a==b", "b==c", "c==d", "d==e", "e!=a"}, false);

    return 0;
}