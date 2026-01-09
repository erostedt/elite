/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

#include <iostream>
#include <unordered_map>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    int rob(vector<int> &nums, size_t index, vector<int> &dp)
    {
        if (index >= nums.size())
        {
            return 0;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        if (index == nums.size() - 1)
        {
            return nums.back();
        }

        auto res = max(rob(nums, index + 1, dp), nums[index] + rob(nums, index + 2, dp));
        dp[index] = res;
        return res;
    }

    int rob(vector<int> &nums)
    {
        if (size(nums) == 0)
        {
            return 0;
        }
        if (size(nums) == 1)
        {
            return nums.front();
        }

        vector<int> table(nums.size(), -1);
        return rob(nums, 0, table);
    }
};

int main()
{
    Solution solution;

    {
        vector nums = {1, 2, 3, 1};

        const int expected_output = 4;
        const int output = solution.rob(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {2, 7, 9, 3, 1};

        const int expected_output = 12;
        const int output = solution.rob(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {1, 2};

        const int expected_output = 2;
        const int output = solution.rob(nums);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
