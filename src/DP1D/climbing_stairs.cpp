/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45
*/

#include "assert.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int climbStairs(int n, unordered_map<int, int> &dp)
    {
        if (const auto entry = dp.find(n); entry != end(dp))
        {
            return entry->second;
        }

        if (n < 0)
        {
            return 0;
        }

        if (n == 0)
        {
            return 1;
        }

        const auto ans = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
        dp[n] = ans;
        return ans;
    }

    int climbStairs(int n)
    {
        unordered_map<int, int> dp{};
        return climbStairs(n, dp);
    }
};

int main()
{

    Solution solution;

    {
        const int n = 2;
        const int expected_output = 2;
        const int output = solution.climbStairs(n);

        Assert::equal(output, expected_output);
    }
    {
        const int n = 3;
        const int expected_output = 3;
        const int output = solution.climbStairs(n);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
