/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at
nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n -
1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to
the last index. Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        if (std::size(nums) < 2)
        {
            return 0;
        }

        for (size_t i = 1; i < std::size(nums); ++i)
        {
            nums[i] = std::max<int>(nums[i - 1], i + nums[i]);
        }

        int steps = 0;
        int current = 0;
        const int target = std::size(nums) - 1;
        while (current < target)
        {
            current = nums.at(current);
            steps++;
        }

        return steps;
    }
};

int main()
{
    Solution solution;
    {
        std::vector nums{2, 3, 1, 1, 4};

        const int expected_output = 2;
        const int output = solution.jump(nums);

        Assert::equal(output, expected_output);
    }
    {
        std::vector nums{2, 3, 0, 1, 4};

        const int expected_output = 2;
        const int output = solution.jump(nums);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
