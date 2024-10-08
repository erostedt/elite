/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of
nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for
space complexity analysis.)
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        std::vector<int> product(nums.size(), 1);
        std::inclusive_scan(std::cbegin(nums), std::prev(std::cend(nums)), std::next(std::begin(product)),
                            std::multiplies<>{}, 1);
        int accum = 1;
        std::transform(std::crbegin(nums), std::prev(std::crend(nums)), std::next(std::crbegin(product)),
                       std::next(std::rbegin(product)), [&accum](const int num, const int prod) {
                           accum *= num;
                           return prod * accum;
                       });
        return product;
    }
};

int main()
{
    Solution solution;
    {
        std::vector nums = {1, 2, 3, 4};

        const std::vector expected_output = {24, 12, 8, 6};
        const std::vector output = solution.productExceptSelf(nums);

        Assert::equals(output, expected_output);
    }
    {
        std::vector nums = {-1, 1, 0, -3, 3};

        const std::vector expected_output = {0, 0, 9, 0, 0};
        const std::vector output = solution.productExceptSelf(nums);

        Assert::equals(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
