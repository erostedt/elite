/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start
and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval
newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still
does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.



Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/

#include <algorithm>
#include <iostream>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.empty())
        {
            return {newInterval};
        }

        const auto it = find_if(begin(intervals), end(intervals),
                                [&](const vector<int> &i) { return i.front() > newInterval.front(); });

        intervals.insert(it, newInterval);
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

int main()
{
    Solution solution;
    {
        vector<vector<int>> intervals = {{1, 3}, {6, 9}};
        vector<int> newInterval = {2, 5};

        const vector<vector<int>> expected_output = {{1, 5}, {6, 9}};
        const vector<vector<int>> output = solution.insert(intervals, newInterval);

        Assert::matrix_equals(output, expected_output);
    }
    {
        vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
        vector<int> newInterval = {4, 8};

        const vector<vector<int>> expected_output = {{1, 2}, {3, 10}, {12, 16}};
        const vector<vector<int>> output = solution.insert(intervals, newInterval);

        Assert::matrix_equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
