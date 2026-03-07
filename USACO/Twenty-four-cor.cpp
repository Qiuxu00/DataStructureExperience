#include <bits/stdc++.h>
using namespace std;

int ans;
int hand[4];                  // The given card hand.
vector<int> hand_permutation; // The generated permutation of the card hand.
bool chosen[4];               // Whether a given card is present in `hand_permutation`.

// Function that takes in two numbers and an operation and returns the result.
int operation(int op, int num1, int num2)
{
    switch (op)
    {
    case 0:
        return num1 + num2;
    case 1:
        return num1 - num2;
    case 2:
        return num1 * num2;
    case 3:
    {
        // The divisor cannot be 0 and the quotient must be a whole number.
        if (num2 == 0 || num1 % num2 != 0)
        {
            return INT32_MIN;
        }
        return num1 / num2;
    }
    }
    return INT32_MIN;
}

// Function that generates all possible permutations of the card hand.
void generate_hand_permutation()
{
    if (hand_permutation.size() == 4)
    {
        // We have generated a permutation, so we can try placing the
        // operators.
        for (int op1 = 0; op1 < 4; op1++)
        {
            for (int op2 = 0; op2 < 4; op2++)
            {
                for (int op3 = 0; op3 < 4; op3++)
                {
                    int first = operation(op1, hand_permutation[0], hand_permutation[1]);
                    // If the operation is invalid, continue;
                    if (first == INT32_MIN)
                    {
                        continue;
                    }

                    int second = operation(op2, first, hand_permutation[2]);
                    if (second == INT32_MIN)
                    {
                        continue;
                    }

                    int third = operation(op3, second, hand_permutation[3]);
                    if (third == INT32_MIN)
                    {
                        continue;
                    }

                    if (third <= 24)
                    {
                        ans = max(ans, third);
                    }
                }
            }
        }

        // Case 2: (( ) ( ))
        for (int op1 = 0; op1 < 4; op1++)
        {
            for (int op2 = 0; op2 < 4; op2++)
            {
                for (int op3 = 0; op3 < 4; op3++)
                {
                    int first =
                        operation(op1, hand_permutation[0], hand_permutation[1]);
                    if (first == INT32_MIN)
                    {
                        continue;
                    }

                    int second =
                        operation(op2, hand_permutation[2], hand_permutation[3]);
                    if (second == INT32_MIN)
                    {
                        continue;
                    }

                    int third = operation(op3, first, second);
                    if (third == INT32_MIN)
                    {
                        continue;
                    }

                    if (third <= 24)
                    {
                        ans = max(ans, third);
                    }
                }
            }
        }
    }
    else
    {
        // Otherwise, we continue to build our permutation array.
        for (int i = 0; i < 4; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            hand_permutation.push_back(hand[i]);
            generate_hand_permutation();
            chosen[i] = false;
            hand_permutation.pop_back();
        }
    }
}

int main()
{
    int num_hands;
    cin >> num_hands;

    for (int h = 0; h < num_hands; h++)
    {
        ans = INT32_MIN;
        for (int i = 0; i < 4; i++)
        {
            cin >> hand[i];
        }

        // Start complete search.
        generate_hand_permutation();
        cout << ans << "\n";
    }
}