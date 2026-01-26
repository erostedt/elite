/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the
same time. You must sell before buying again. Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

#include "assert.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices, int day, int transactions, int holding_stock, vector<vector<vector<int>>> &dp)
    {
        if (transactions == 2 || day >= (int)prices.size())
        {
            return 0;
        }

        if (dp[day][transactions][holding_stock] != -1)
        {
            return dp[day][transactions][holding_stock];
        }

        int ans;
        // holding stock
        if (holding_stock)
        {
            int dont_sell = maxProfit(prices, day + 1, transactions, 1, dp);
            int sell = prices[day] + maxProfit(prices, day + 1, transactions + 1, 0, dp);
            ans = max(dont_sell, sell);
        }
        // not holding stock
        else
        {
            int dont_buy = maxProfit(prices, day + 1, transactions, 0, dp);
            int buy = -prices[day] + maxProfit(prices, day + 1, transactions, 1, dp);
            ans = max(dont_buy, buy);
        }

        dp[day][transactions][holding_stock] = ans;
        return ans;
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, -1)));
        return maxProfit(prices, 0, 0, 0, dp);
    }
};

int main()
{

    Solution solution;

    {
        vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
        const int output = solution.maxProfit(prices);
        const int expected_output = 6;

        Assert::equal(output, expected_output);
    }

    {
        vector<int> prices = {1, 2, 3, 4, 5};
        const int output = solution.maxProfit(prices);
        const int expected_output = 4;

        Assert::equal(output, expected_output);
    }

    {
        vector<int> prices = {7, 6, 4, 3, 1};
        const int output = solution.maxProfit(prices);
        const int expected_output = 0;

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
