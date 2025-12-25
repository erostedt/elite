/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums
is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b


Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"


Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.
*/

#include <algorithm>
#include <iostream>
#include <span>
#include <string>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    string make_range(int start, int end)
    {
        auto s = to_string(start);
        if (start == end)
        {
            return s;
        }
        return s + "->" + to_string(end);
    }
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ranges{};
        span<int> xs = nums;
        while (!xs.empty())
        {
            const auto it = adjacent_find(begin(xs), end(xs), [](int c, int n) { return c + 1 != n; });
            if (it == end(xs))
            {
                ranges.push_back(make_range(xs.front(), xs.back()));
                return ranges;
            }
            ranges.push_back(make_range(xs.front(), *it));
            xs = xs.subspan(distance(begin(xs), next(it)));
        }
        return ranges;
    }
};

int main()
{
    Solution solution;
    {
        std::vector<int> nums = {0, 1, 2, 4, 5, 7};

        const std::vector<std::string> expected_output = {"0->2", "4->5", "7"};
        const std::vector<std::string> output = solution.summaryRanges(nums);

        Assert::equals(output, expected_output);
    }
    {
        std::vector<int> nums = {0, 2, 3, 4, 6, 8, 9};

        const std::vector<std::string> expected_output = {"0", "2->4", "6", "8->9"};
        const std::vector<std::string> output = solution.summaryRanges(nums);

        Assert::equals(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
