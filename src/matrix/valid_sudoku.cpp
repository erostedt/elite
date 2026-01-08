/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


Example 1:


Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in
the top left 3x3 sub-box, it is invalid.


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

#include <array>
#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    int index(char digit)
    {
        return digit - '1';
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        const size_t grid_size = 9;
        const size_t cell_size = 3;

        for (const auto &row : board)
        {
            std::array<bool, grid_size> taken{};
            for (const auto &digit : row)
            {
                if (digit == '.')
                {
                    continue;
                }

                auto &cell_taken = taken[index(digit)];
                if (cell_taken)
                {
                    return false;
                }
                cell_taken = true;
            }
        }

        for (size_t c = 0; c < grid_size; ++c)
        {
            std::array<bool, grid_size> taken{};
            for (size_t r = 0; r < grid_size; ++r)
            {
                char digit = board[r][c];
                if (digit == '.')
                {
                    continue;
                }
                auto &cell_taken = taken[index(digit)];
                if (cell_taken)
                {
                    return false;
                }
                cell_taken = true;
            }
        }

        for (size_t cr = 0; cr < grid_size / cell_size; ++cr)
        {
            for (size_t cc = 0; cc < grid_size / cell_size; ++cc)
            {
                std::array<bool, grid_size> taken{};
                size_t row_start = cr * cell_size;
                size_t row_end = (cr + 1) * cell_size;
                size_t col_start = cc * cell_size;
                size_t col_end = (cc + 1) * cell_size;
                for (size_t r = row_start; r < row_end; ++r)
                {
                    for (size_t c = col_start; c < col_end; ++c)
                    {
                        char digit = board[r][c];
                        if (digit == '.')
                        {
                            continue;
                        }

                        auto &cell_taken = taken[index(digit)];
                        if (cell_taken)
                        {
                            return false;
                        }
                        cell_taken = true;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    {
        vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

        const bool expected_output = true;
        const bool output = solution.isValidSudoku(board);

        Assert::equal(output, expected_output);
    }
    {
        vector<vector<char>> board = {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

        const bool expected_output = false;
        const bool output = solution.isValidSudoku(board);

        Assert::equal(output, expected_output);
    }

    {
        vector<vector<char>> board = {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

        const bool expected_output = false;
        const bool output = solution.isValidSudoku(board);

        Assert::equal(output, expected_output);
    }

    {
        vector<vector<char>> board = {
            {'.', '.', '.', '.', '5', '.', '.', '1', '.'}, {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '3', '.', '.', '1'}, {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
            {'.', '.', '2', '.', '7', '.', '.', '.', '.'}, {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '2', '.', '.', '.'}, {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
            {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};

        const bool expected_output = false;
        const bool output = solution.isValidSudoku(board);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
