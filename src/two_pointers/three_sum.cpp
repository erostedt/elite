/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

#include "assert.hpp"

using namespace std;

struct Triplet
{
    int first;
    int second;
    int third;
};

struct TripletEqual
{
    bool operator()(const Triplet &lhs, const Triplet &rhs) const
    {
        return lhs.first == rhs.first && lhs.second == rhs.second && lhs.third == rhs.third;
    }
};

struct TripletHash
{
    size_t operator()(const Triplet &triplet) const
    {
        std::size_t hash = 0;
        std::hash<int> int_hasher{};
        hash ^= int_hasher(triplet.first) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        hash ^= int_hasher(triplet.second) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        hash ^= int_hasher(triplet.third) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        return hash;
    }
};

using TripletSet = std::unordered_set<Triplet, TripletHash, TripletEqual>;

template <typename Iterator>
void _two_sum(Iterator forward, Iterator backward, int target, std::vector<std::vector<int>> &triplets,
              TripletSet &seen)
{
    while (forward < backward)
    {
        const int sum = *forward + *backward;
        if (sum == target)
        {
            const Triplet triplet{-target, *forward, *backward};
            if (!seen.contains(triplet))
            {
                triplets.push_back({-target, *forward, *backward});
                seen.insert(triplet);
            }
            ++forward;
        }
        else if (sum > target)
        {
            --backward;
        }
        else
        {
            ++forward;
        }
    }
}

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (std::size(nums) < 3)
        {
            return {};
        }

        std::sort(std::begin(nums), std::end(nums));

        std::vector<std::vector<int>> triplets;
        auto forward = std::cbegin(nums);
        auto last = std::prev(std::cend(nums));
        TripletSet seen;
        while (forward < last)
        {
            const int target = -(*forward);
            _two_sum(std::next(forward), last, target, triplets, seen);
            ++forward;
        }
        return triplets;
    }
};

int main()
{
    Solution solution;
    {
        std::vector numbers = {-1, 0, 1, 2, -1, -4};

        const std::vector<std::vector<int>> expected_output = {{-1, -1, 2}, {-1, 0, 1}};
        const std::vector<std::vector<int>> output = solution.threeSum(numbers);

        Assert::matrix_equals(output, expected_output);
    }
    {
        std::vector numbers = {0, 1, 1};

        const std::vector<std::vector<int>> expected_output = {};
        const std::vector<std::vector<int>> output = solution.threeSum(numbers);

        Assert::matrix_equals(output, expected_output);
    }
    {
        std::vector numbers = {0, 0, 0};

        const std::vector<std::vector<int>> expected_output = {{0, 0, 0}};
        const std::vector<std::vector<int>> output = solution.threeSum(numbers);

        Assert::matrix_equals(output, expected_output);
    }
    {
        std::vector numbers = {0, 0, 0, 0};

        const std::vector<std::vector<int>> expected_output = {{0, 0, 0}};
        const std::vector<std::vector<int>> output = solution.threeSum(numbers);

        Assert::matrix_equals(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
