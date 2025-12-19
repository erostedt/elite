/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of
the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    static bool interval_cmp(const vector<int> &i1, const vector<int> &i2)
    {
        return i1.front() < i2.front();
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return {};
        }

        sort(begin(intervals), end(intervals), interval_cmp);
        vector<vector<int>> merged{intervals.front()};
        for (size_t i = 1; i < intervals.size(); ++i)
        {
            auto &last = merged.back();
            auto &curr = intervals[i];

            // Overlap
            if (curr.front() <= last.back())
            {
                last.back() = max(last.back(), curr.back());
            }
            else
            {
                merged.push_back(curr);
            }
        }
        return merged;
    }
};

void print_intervals(const vector<vector<int>> &intervals)
{
    for (const auto &i : intervals)
    {
        std::cout << i.front() << ", " << i.back() << std::endl;
    }
}

int main()
{
    Solution solution;
    {
        std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

        print_intervals(intervals);
        const std::vector<std::vector<int>> expected_output = {{1, 6}, {8, 10}, {15, 18}};
        const std::vector<std::vector<int>> output = solution.merge(intervals);
        std::cout << "***************" << std::endl;
        print_intervals(output);

        Assert::matrix_equals(output, expected_output);
    }
    {
        std::vector<std::vector<int>> intervals = {{1, 4}, {4, 5}};

        const std::vector<std::vector<int>> expected_output = {{1, 5}};
        const std::vector<std::vector<int>> output = solution.merge(intervals);

        Assert::matrix_equals(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
