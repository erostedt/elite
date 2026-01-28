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
#include <unordered_set>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<size_t> zero_rows{};
        unordered_set<size_t> zero_cols{};
        for (size_t r = 0; r < matrix.size(); ++r)
        {
            for (size_t c = 0; c < matrix[r].size(); ++c)
            {
                if (matrix[r][c] == 0)
                {
                    zero_rows.insert(r);
                    zero_cols.insert(c);
                }
            }
        }

        for (size_t r : zero_rows)
        {
            for (size_t c = 0; c < matrix[r].size(); ++c)
            {
                matrix[r][c] = 0;
            }
        }
        for (size_t c : zero_cols)
        {
            for (size_t r = 0; r < matrix.size(); ++r)
            {
                matrix[r][c] = 0;
            }
        }
    }
};

int main()
{
    using Matrix = vector<vector<int>>;

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

    cout << "All passed" << endl;
}
