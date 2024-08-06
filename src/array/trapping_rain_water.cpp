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

#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        throw Assert::NotImplemented(__FUNCTION__);
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        const int expected_output = 6;
        const int output = s.trap(input);
        Assert::equal(output, expected_output);
    }
    {
        std::vector<int> input = {4, 2, 0, 3, 2, 5};
        const int expected_output = 9;
        const int output = s.trap(input);
        Assert::equal(output, expected_output);
    }
    std::cout << "All passed" << std::endl;
}
