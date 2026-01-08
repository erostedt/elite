/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate
another 2D matrix and do the rotation.

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;
void print_matrix(const vector<vector<int>> &m)
{
    for (const auto &r : m)
    {
        for (const auto c : r)
        {
            cout << c << ' ';
        }
        cout << endl;
    }
}

class Solution
{
  public:
    void transpose(vector<vector<int>> &matrix)
    {
        const size_t row_count = matrix.size();
        const size_t col_count = matrix[0].size();
        for (size_t r = 0; r < row_count; ++r)
        {
            for (size_t c = r + 1; c < col_count; ++c)
            {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            return;
        }
        transpose(matrix);
        for (auto &row : matrix)
        {
            reverse(begin(row), end(row));
        }
    }
};

int main()
{
    using Matrix = vector<vector<int>>;

    Solution solution;
    {
        Matrix matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        const Matrix expected_output = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
        solution.rotate(matrix);

        Assert::matrix_equals(matrix, expected_output);
    }
    {
        Matrix matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

        const Matrix expected_output = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
        solution.rotate(matrix);

        Assert::matrix_equals(matrix, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
