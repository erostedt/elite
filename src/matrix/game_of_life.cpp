/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the
British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead
(represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following
four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births
and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.



Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]


Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.


Follow up:

Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells
first and then use their updated values to update other cells. In this question, we represent the board using a 2D
array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border
of the array (i.e., live cells reach the border). How would you address these problems?
*/

#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    int neighbor_count(const vector<vector<int>> &board, size_t r, size_t c)
    {
        const size_t row_count = board.size();
        const size_t col_count = board[0].size();
        size_t rstart = r > 0 ? r - 1 : 0;
        size_t rend = r < row_count - 1 ? r + 1 : row_count - 1;
        size_t cstart = c > 0 ? c - 1 : 0;
        size_t cend = c < col_count - 1 ? c + 1 : col_count - 1;
        int count = 0;
        for (size_t row = rstart; row <= rend; ++row)
        {
            for (size_t col = cstart; col <= cend; ++col)
            {
                count += board[row][col];
            }
        }
        count -= board[r][c];
        return count;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        if (board.empty())
        {
            return;
        }

        vector<vector<int>> next_state = board;

        const size_t row_count = board.size();
        const size_t col_count = board[0].size();

        for (size_t r = 0; r < row_count; ++r)
        {
            for (size_t c = 0; c < col_count; ++c)
            {
                int count = neighbor_count(board, r, c);
                if (board[r][c] == 1)
                {
                    if (count < 2 || count > 3)
                    {
                        next_state[r][c] = 0;
                    }
                }
                else if (count == 3)
                {
                    next_state[r][c] = 1;
                }
            }
        }

        swap(board, next_state);
    }
};

int main()
{
    using Board = vector<vector<int>>;

    Solution solution;
    {
        Board board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

        const Board expected_output = {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};
        solution.gameOfLife(board);

        Assert::matrix_equals(board, expected_output);
    }
    {
        Board board = {{1, 1}, {1, 0}};
        const Board expected_output = {{1, 1}, {1, 1}};
        solution.gameOfLife(board);

        Assert::matrix_equals(board, expected_output);
    }

    cout << "All passed" << endl;
}
