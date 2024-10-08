/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.

bool insert(int val)
Inserts an item val into the set if not present. Returns true if the item was not present, false
otherwise.

bool remove(int val)
Removes an item val from the set if present. Returns true if the item was present, false
otherwise.

int getRandom()
Returns a random element from the current set of elements (it's guaranteed that at least one
element exists when this method is called). Each element must have the same probability of being returned. You must

Implement the functions of the class such that each function works in average O(1) time complexity.


Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.


Constraints:

-231 <= val <= 231 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.
*/

#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

#include "assert.hpp"

using namespace std;

class RandomizedSet
{
  public:
    RandomizedSet()
    {
        m_random_generator = std::mt19937(m_random_device());
    }

    bool insert(int val)
    {
        if (m_index_lookup.contains(val))
        {
            return false;
        }
        m_index_lookup[val] = m_elements.size();
        m_elements.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (!m_index_lookup.contains(val))
        {
            return false;
        }
        const auto index = m_index_lookup.at(val);
        m_index_lookup.at(m_elements.back()) = index;
        std::swap(m_elements.at(index), m_elements.back());
        m_elements.pop_back();
        m_index_lookup.erase(val);
        return true;
    }

    int getRandom()
    {
        std::uniform_int_distribution<int> distribution(0, m_elements.size() - 1);
        return m_elements.at(distribution(m_random_generator));
    }

    void show()
    {
        std::cout << "Lookup: " << std::endl;
        for (const auto &[key, value] : m_index_lookup)
        {
            std::cout << key << " -> " << value << std::endl;
        }
        std::cout << "Elements: " << std::endl;
        for (const auto &element : m_elements)
        {
            std::cout << element << std::endl;
        }
    }

  private:
    std::unordered_map<int, size_t> m_index_lookup;
    std::vector<int> m_elements;
    std::mt19937 m_random_generator;
    std::random_device m_random_device;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    {
        RandomizedSet rset{};
        Assert::equal(rset.insert(1), true);
        Assert::equal(rset.remove(2), false);
        Assert::equal(rset.insert(2), true);
        Assert::equal_one_of(rset.getRandom(), {1, 2});
        Assert::equal(rset.remove(1), true);
        Assert::equal(rset.insert(2), false);
        Assert::equal(rset.getRandom(), 2);
    }

    {
        RandomizedSet rset{};
        Assert::equal(rset.insert(0), true);
        rset.show();
        Assert::equal(rset.insert(1), true);
        rset.show();
        Assert::equal(rset.remove(0), true);
        rset.show();
        Assert::equal(rset.insert(2), true);
        rset.show();
        Assert::equal(rset.remove(1), true);
        rset.show();
        Assert::equal(rset.getRandom(), 2);
    }
    std::cout << "All passed" << std::endl;
}
