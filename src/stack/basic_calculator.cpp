/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of
the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as
eval().



Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23


Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    string parse_number(string_view str)
    {
        stringstream stream;
        for (char c : str)
        {
            if (!isdigit(c))
            {
                break;
            }
            stream << c;
        }
        return stream.str();
    }

    vector<string> tokenize(string &&s)
    {
        vector<string> tokens{};
        string_view v = s;
        while (!v.empty())
        {
            switch (v.front())
            {
            case '(':
            case ')':
            case '+':
            case '-': {
                tokens.push_back(string(1, v.front()));
                v = v.substr(1);
                break;
            }
            case ' ':
                v = v.substr(1);
                break;

            default: {
                string number = parse_number(v);
                v = v.substr(number.size());
                tokens.push_back(number);
            }
            }
        }
        return tokens;
    }

    void print_vec(const vector<string> &v)
    {
        for (const auto &e : v)
        {
            cout << e << ' ';
        }
        cout << endl;
    }

    string evaluate_inner(vector<string> expr)
    {
        if (expr.front() == "-")
        {
            expr.erase(begin(expr));
            expr.front() = expr.front().front() == '-' ? expr.front().substr(1) : "-" + expr.front();
        }

        if (expr.size() == 1)
        {
            return expr.front();
        }

        int result = atoi(expr[0].c_str());
        for (size_t i = 2; i < expr.size(); i += 2)
        {
            const string &op = expr[i - 1];
            int rhs = atoi(expr[i].c_str());
            switch (op.front())
            {
            case '+': {
                result += rhs;
                break;
            }
            case '-': {
                result -= rhs;
                break;
            }
            }
        }
        return to_string(result);
    }

    int calculate(string s)
    {
        auto tokens = tokenize(std::move(s));
        vector<string> stack{};
        for (const auto &token : tokens)
        {
            if (token != ")")
            {
                stack.push_back(token);
                continue;
            }

            vector<string> inner_expr{};
            do
            {
                inner_expr.push_back(stack.back());
                stack.pop_back();
            } while (stack.back() != "(");
            stack.pop_back();
            reverse(begin(inner_expr), end(inner_expr));
            stack.push_back(evaluate_inner(inner_expr));
        }
        string result = evaluate_inner(stack);
        return atoi(result.c_str());
    }
};

int main()
{
    Solution solution;

    {
        const string s = "-(-2)+4";
        const int expected_output = 6;
        const int output = solution.calculate(s);

        Assert::equal(output, expected_output);
    }

    {
        const string s = "1 + 1";
        const int expected_output = 2;
        const int output = solution.calculate(s);

        Assert::equal(output, expected_output);
    }

    {
        const string s = "-1 + 1";
        const int expected_output = 0;
        const int output = solution.calculate(s);

        Assert::equal(output, expected_output);
    }

    {
        const string s = "-(1 + 1)";
        const int expected_output = -2;
        const int output = solution.calculate(s);

        Assert::equal(output, expected_output);
    }

    {
        const string s = "(1+ 2 - 3)";
        const int expected_output = 0;
        const int output = solution.calculate(s);

        Assert::equal(output, expected_output);
    }

    {
        const string s = " 2-1 + 2 ";
        const int expected_output = 3;
        const int output = solution.calculate(s);

        Assert::equal(output, expected_output);
    }

    {
        const string s = "(1+(4+5+2)-3)+(6+8)";
        const int expected_output = 23;
        const int output = solution.calculate(s);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
