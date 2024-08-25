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


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        NOT_IMPLEMENTED;
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
