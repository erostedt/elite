/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that
they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1
< index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.



Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].


Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/

#include <iostream>
#include <iterator>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        if (std::size(numbers) < 2)
        {
            return {};
        }

        auto start = std::cbegin(numbers);
        auto forward = std::cbegin(numbers);
        auto backward = std::prev(std::cend(numbers));
        while (forward <= backward)
        {
            const int sum = *forward + *backward;
            if (sum == target)
            {
                break;
            }
            else if (sum > target)
            {
                --backward;
            }
            else
            {
                ++forward;
            }
        }

        const int index1 = static_cast<int>(std::distance(start, forward)) + 1;
        const int index2 = static_cast<int>(std::distance(start, backward)) + 1;

        return {index1, index2};
    }
};

int main()
{
    Solution solution;
    {
        std::vector numbers = {2, 7, 11, 15};
        const int target = 9;

        const std::vector expected_output = {1, 2};
        const std::vector output = solution.twoSum(numbers, target);

        Assert::equals(output, expected_output);
    }
    {
        std::vector numbers = {2, 3, 4};
        const int target = 6;

        const std::vector expected_output = {1, 3};
        const std::vector output = solution.twoSum(numbers, target);

        Assert::equals(output, expected_output);
    }
    {
        std::vector numbers = {-1, 0};
        const int target = -1;

        const std::vector expected_output = {1, 2};
        const std::vector output = solution.twoSum(numbers, target);

        Assert::equals(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
