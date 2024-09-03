/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such
that nums[i] == nums[j] and abs(i - j) <= k.



Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false


Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

#include <iostream>
#include <unordered_map>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        std::unordered_map<int, int> num_to_max_index;
        size_t max = k;
        for (size_t i = 0; i < std::size(nums); ++i)
        {
            const auto it = num_to_max_index.find(nums[i]);
            if (it != std::cend(num_to_max_index) && (i - it->second) <= max)
            {
                return true;
            }
            num_to_max_index[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    {
        std::vector<int> nums = {1, 2, 3, 1};
        const int k = 3;

        const bool expected_output = true;
        const bool output = solution.containsNearbyDuplicate(nums, k);

        Assert::equal(output, expected_output);
    }
    {
        std::vector<int> nums = {1, 0, 1, 1};
        const int k = 1;

        const bool expected_output = true;
        const bool output = solution.containsNearbyDuplicate(nums, k);

        Assert::equal(output, expected_output);
    }
    {
        std::vector<int> nums = {1, 2, 3, 1, 2, 3};
        const int k = 2;

        const bool expected_output = false;
        const bool output = solution.containsNearbyDuplicate(nums, k);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
