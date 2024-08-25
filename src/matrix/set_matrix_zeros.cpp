/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    using Matrix = std::vector<std::vector<int>>;

    Solution solution;
    {
        Matrix matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

        const Matrix expected_output = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
        solution.setZeroes(matrix);

        Assert::matrix_equals(matrix, expected_output);
    }
    {
        Matrix matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        const Matrix expected_output = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
        solution.setZeroes(matrix);

        Assert::matrix_equals(matrix, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
