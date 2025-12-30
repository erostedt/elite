
/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22


Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

#include "assert.hpp"
#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> unevaluated = {};
        for (const auto &token : tokens)
        {
            if (token == "+")
            {
                auto rhs = unevaluated.back();
                unevaluated.pop_back();
                auto lhs = unevaluated.back();
                unevaluated.pop_back();
                unevaluated.push_back(lhs + rhs);
            }
            else if (token == "-")
            {
                auto rhs = unevaluated.back();
                unevaluated.pop_back();
                auto lhs = unevaluated.back();
                unevaluated.pop_back();
                unevaluated.push_back(lhs - rhs);
            }
            else if (token == "*")
            {
                auto rhs = unevaluated.back();
                unevaluated.pop_back();
                auto lhs = unevaluated.back();
                unevaluated.pop_back();
                unevaluated.push_back(lhs * rhs);
            }
            else if (token == "/")
            {
                auto rhs = unevaluated.back();
                unevaluated.pop_back();
                auto lhs = unevaluated.back();
                unevaluated.pop_back();
                unevaluated.push_back(lhs / rhs);
            }
            else
            {
                unevaluated.push_back(atoi(token.c_str()));
            }
        }
        return unevaluated.back();
    }
};

int main()
{

    Solution solution;

    {
        vector<string> tokens = {"2", "1", "+", "3", "*"};

        const int expected_output = 9;
        const int output = solution.evalRPN(tokens);

        Assert::equal(output, expected_output);
    }

    {
        vector<string> tokens = {"4", "13", "5", "/", "+"};

        const int expected_output = 6;
        const int output = solution.evalRPN(tokens);

        Assert::equal(output, expected_output);
    }

    {
        vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

        const int expected_output = 22;
        const int output = solution.evalRPN(tokens);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
