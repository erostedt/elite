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
        vector<int> result{};
        if (matrix.empty())
        {
            return result;
        }

        result.reserve(matrix.size() * matrix[0].size());
        int top = 0;
        int bottom = (int)matrix.size() - 1;
        int left = 0;
        int right = (int)matrix[0].size() - 1;

        while (true)
        {
            for (int x = left; x <= right; ++x)
            {
                result.push_back(matrix[top][x]);
            }
            ++top;
            if (top > bottom)
            {
                break;
            }

            for (int y = top; y <= bottom; ++y)
            {
                result.push_back(matrix[y][right]);
            }
            --right;
            if (left > right)
            {
                break;
            }

            for (int x = right; x >= left; --x)
            {
                result.push_back(matrix[bottom][x]);
            }
            --bottom;
            if (top > bottom)
            {
                break;
            }

            for (int y = bottom; y >= top; --y)
            {
                result.push_back(matrix[y][left]);
            }
            ++left;
            if (left > right)
            {
                break;
            }
        }
        return result;
    }
};

int main()
{
    using Matrix = vector<vector<int>>;

    Solution solution;
    {
        Matrix matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        const vector<int> expected_output = {1, 2, 3, 6, 9, 8, 7, 4, 5};
        const vector<int> output = solution.spiralOrder(matrix);

        Assert::equals(output, expected_output);
    }

    {
        Matrix matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

        const vector<int> expected_output = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
        const vector<int> output = solution.spiralOrder(matrix);

        Assert::equals(output, expected_output);
    }
    cout << "All passed" << endl;
}
