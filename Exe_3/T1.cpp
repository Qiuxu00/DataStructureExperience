#include <iostream>
#include <stack>
using namespace std;

bool is_Correct(string target)
{
    stack<char> result;
    for (char i : target)
    {
        if (i == '(' || i == '[' || i == '{')
        {
            result.push(i);
        }
        else if (i == ')' || i == ']' || i == '}')
        {
            if (result.empty())
            {
                return false;
            }
            if (i == ')' && result.top() != '(')
            {
                return false;
            }
            if (i == ']' && result.top() != '[')
            {
                return false;
            }
            if (i == '}' && result.top() != '{')
            {
                return false;
            }
            result.pop();
        }
    }
    if (!result.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    cout << boolalpha << is_Correct("{(6+3)[]") << endl;
    return 0;
}