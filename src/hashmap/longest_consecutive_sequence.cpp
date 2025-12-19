/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3


Constraints:

0 <= nums.length <= 105
-10^9 <= nums[i] <= 10^9
*/

#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> remaining = {begin(nums), end(nums)};
        int max_count = 0;
        for (const auto num : nums)
        {
            if (!remaining.contains(num))
            {
                continue;
            }

            auto first = num;
            auto last = num + 1;
            while (remaining.contains(first))
            {
                remaining.erase(first);
                --first;
            }

            while (remaining.contains(last))
            {
                remaining.erase(last);
                ++last;
            }

            const auto count = last - first - 1;
            max_count = max(count, max_count);
        }
        return max_count;
    }
};

int main()
{
    Solution solution;
    {
        std::vector<int> nums = {100, 4, 200, 1, 3, 2};

        const int expected_output = 4;
        const int output = solution.longestConsecutive(nums);

        Assert::equal(output, expected_output);
    }
    {
        std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

        const int expected_output = 9;
        const int output = solution.longestConsecutive(nums);

        Assert::equal(output, expected_output);
    }
    std::cout << "All passed" << std::endl;
}
