/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the
array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible
to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

#include <iostream>
#include <iterator>
#include <vector>

#include "assert.hpp"

using namespace std;

template <typename Iterator> bool can_reach_target(const Iterator current, const Iterator target)
{
    return std::distance(current, target) <= *current;
}

template <typename Iterator> bool can_jump(const Iterator beginning, const Iterator current, const Iterator target)
{
    if (current == beginning)
    {
        return can_reach_target(current, target);
    }
    else if (can_reach_target(current, target))
    {
        return can_jump(beginning, std::prev(current), current);
    }
    return can_jump(beginning, std::prev(current), target);
}

class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        return (nums.size() < 2)
                   ? true
                   : can_jump(std::cbegin(nums), std::prev(std::cend(nums), 2), std::prev(std::cend(nums)));
    }
};

int main()
{
    Solution solution;
    {
        std::vector nums{2, 3, 1, 1, 4};

        const bool expected_output = true;
        const bool output = solution.canJump(nums);

        Assert::equal(output, expected_output);
    }
    {
        std::vector nums{3, 2, 1, 0, 4};

        const bool expected_output = false;
        const bool output = solution.canJump(nums);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
