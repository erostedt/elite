/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to
target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

#include <iostream>
#include <unordered_map>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, size_t> value_to_index;
        for (size_t i = 0; i < size(nums); ++i)
        {
            int diff = target - nums[i];
            if (value_to_index.contains(diff))
            {
                return {static_cast<int>(value_to_index.at(diff)), static_cast<int>(i)};
            }
            value_to_index[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution solution;
    {
        vector nums = {2, 7, 11, 15};
        const int target = 9;

        const vector expected_output = {0, 1};
        const vector output = solution.twoSum(nums, target);

        Assert::equals(output, expected_output);
    }

    {
        vector nums = {3, 2, 4};
        const int target = 6;

        const vector expected_output = {1, 2};
        const vector output = solution.twoSum(nums, target);

        Assert::equals(output, expected_output);
    }

    {
        vector nums = {3, 3};
        const int target = 6;

        const vector expected_output = {0, 1};
        const vector output = solution.twoSum(nums, target);

        Assert::equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
