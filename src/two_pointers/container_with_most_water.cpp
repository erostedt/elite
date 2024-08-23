/*
 * You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of
the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.


Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water
(blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
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
    int maxArea(vector<int> &height)
    {
        if (std::size(height) < 2)
        {
            return 0;
        }

        auto forward = std::cbegin(height);
        auto backward = std::prev(std::cend(height));

        int max_seen = 0;
        while (forward < backward)
        {
            max_seen =
                std::max(max_seen, std::min(*forward, *backward) * static_cast<int>(std::distance(forward, backward)));

            if (*forward > *backward)
            {
                --backward;
            }
            else
            {
                ++forward;
            }
        }
        return max_seen;
    }
};

int main()
{
    Solution solution;
    {
        std::vector height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

        const int expected_output = 49;
        const int output = solution.maxArea(height);

        Assert::equal(output, expected_output);
    }
    {
        std::vector height = {1, 1};

        const int expected_output = 1;
        const int output = solution.maxArea(height);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
