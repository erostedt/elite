/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.


Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/

#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    int candy(vector<int> &ratings)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        std::vector ratings = {1, 0, 2};

        const int expected_output = 5;
        const int output = solution.candy(ratings);

        Assert::equal(output, expected_output);
    }
    {
        std::vector ratings = {1, 2, 2};

        const int expected_output = 4;
        const int output = solution.candy(ratings);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
