/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

#include "assert.hpp"
#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;

using DP = vector<vector<int>>;

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums, int index, int prev_index, DP &dp)
    {
        if (index == size(nums))
        {
            return 0;
        }

        auto &dp_entry = dp[index][prev_index + 1];
        if (dp_entry != -1)
        {
            return dp_entry;
        }

        const int skip = lengthOfLIS(nums, index + 1, prev_index, dp);
        const int take =
            prev_index == -1 || nums[index] > nums[prev_index] ? 1 + lengthOfLIS(nums, index + 1, index, dp) : 0;
        const int best = max(skip, take);
        dp_entry = best;
        return best;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> row(size(nums) + 1, -1);
        DP dp(size(nums), row);
        return lengthOfLIS(nums, 0, -1, dp);
    }
};

int main()
{

    Solution solution;

    {
        vector nums = {10, 9, 2, 5, 3, 7, 101, 18};
        const int expected_output = 4;
        const int output = solution.lengthOfLIS(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {10, 9, 2, 5, 3, 7, 101, 18};
        const int expected_output = 4;
        const int output = solution.lengthOfLIS(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {7, 7, 7, 7, 7, 7, 7};
        const int expected_output = 1;
        const int output = solution.lengthOfLIS(nums);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
