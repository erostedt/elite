/*
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped. Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

#include "assert.hpp"

using namespace std;
namespace rs = std::ranges;

template <typename Iterator> int get_water_between(Iterator beginning, Iterator end)
{
    int max_seen = *beginning;
    return std::accumulate(beginning, end, 0, [&max_seen](const int accum, const int height) {
        max_seen = rs::max(max_seen, height);
        return accum + max_seen - height;
    });
}

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        const auto max_it = std::max_element(std::cbegin(height), std::cend(height));
        return get_water_between(std::cbegin(height), std::next(max_it)) +
               get_water_between(std::crbegin(height), std::reverse_iterator(max_it));
    }
};

int main()
{
    Solution solution;
    {
        std::vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

        const int expected_output = 6;
        const int output = solution.trap(input);

        Assert::equal(output, expected_output);
    }
    {
        std::vector<int> input = {4, 2, 0, 3, 2, 5};

        const int expected_output = 9;
        const int output = solution.trap(input);

        Assert::equal(output, expected_output);
    }
    std::cout << "All passed" << std::endl;
}
