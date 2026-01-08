/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a
total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 104
*/

#include "assert.hpp"
#include <iostream>
#include <limits>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount, unordered_map<int, int> &dp)
    {
        if (const auto entry = dp.find(amount); entry != end(dp))
        {
            return entry->second;
        }

        if (amount == 0)
        {
            return 0;
        }

        if (amount < 0)
        {
            return numeric_limits<int>::max();
        }
        int best = numeric_limits<int>::max();
        for (const auto coin : coins)
        {
            const auto res = coinChange(coins, amount - coin, dp);
            if (res != numeric_limits<int>::max())
            {
                best = min(1 + res, best);
            }
        }

        dp[amount] = best;
        return best;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        unordered_map<int, int> dp{};
        const auto res = coinChange(coins, amount, dp);
        return res == numeric_limits<int>::max() ? -1 : res;
    }
};

int main()
{

    Solution solution;

    {
        vector<int> coins = {1, 2, 5};
        const int amount = 11;
        const int expected_output = 3;
        const int output = solution.coinChange(coins, amount);

        Assert::equal(output, expected_output);
    }

    {
        vector<int> coins = {2};
        const int amount = 3;
        const int expected_output = -1;
        const int output = solution.coinChange(coins, amount);

        Assert::equal(output, expected_output);
    }

    {
        vector<int> coins = {1};
        const int amount = 0;
        const int expected_output = 0;
        const int output = solution.coinChange(coins, amount);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
