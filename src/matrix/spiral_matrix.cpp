/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        const std::vector<int> expected_output = {1, 2, 3, 6, 9, 8, 7, 4, 5};
        const std::vector<int> output = solution.spiralOrder(matrix);

        Assert::equals(output, expected_output);
    }
    {
        std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

        const std::vector<int> expected_output = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
        const std::vector<int> output = solution.spiralOrder(matrix);

        Assert::equals(output, expected_output);
    }
    std::cout << "All passed" << std::endl;
}
