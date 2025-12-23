/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false



Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include "assert.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        vector<char> stack{};
        for (const auto c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[': {
                stack.push_back(c);
                break;
            }
            case ')': {
                if (stack.empty() || stack.back() != '(')
                {
                    return false;
                }
                stack.pop_back();
                break;
            }
            case ']': {
                if (stack.empty() || stack.back() != '[')
                {
                    return false;
                }
                stack.pop_back();
                break;
            }
            case '}': {
                if (stack.empty() || stack.back() != '{')
                {
                    return false;
                }
                stack.pop_back();
                break;
            }
            }
        }
        return stack.empty();
    }
};

int main()
{

    Solution solution;
    {
        string s = "()";

        const bool expected_output = true;
        const bool output = solution.isValid(s);

        Assert::equal(output, expected_output);
    }

    {
        string s = "()[]{}";

        const bool expected_output = true;
        const bool output = solution.isValid(s);

        Assert::equal(output, expected_output);
    }

    {
        string s = "(]";

        const bool expected_output = false;
        const bool output = solution.isValid(s);

        Assert::equal(output, expected_output);
    }

    {
        string s = "([])";

        const bool expected_output = true;
        const bool output = solution.isValid(s);

        Assert::equal(output, expected_output);
    }

    {
        string s = "([)]";

        const bool expected_output = false;
        const bool output = solution.isValid(s);

        Assert::equal(output, expected_output);
    }
    {
        string s = "[";

        const bool expected_output = false;
        const bool output = solution.isValid(s);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
