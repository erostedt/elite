/*
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to
transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For
example, '...' and '....' are valid directory or file names. The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.



Example 1:

Input: path = "/home/"

Output: "/home"

Explanation:

The trailing slash should be removed.

Example 2:

Input: path = "/home//foo/"

Output: "/home/foo"

Explanation:

Multiple consecutive slashes are replaced by a single one.

Example 3:

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).

Example 4:

Input: path = "/../"

Output: "/"

Explanation:

Going one level up from the root directory is not possible.

Example 5:

Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.



Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
*/

#include "assert.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
  public:
    vector<string> split(const string &s, char delimiter)
    {
        vector<string> tokens;
        istringstream stream(s);
        string item;

        while (getline(stream, item, delimiter))
        {
            tokens.push_back(item);
        }
        return tokens;
    }

    string simplifyPath(string path)
    {
        auto parts = split(path, '/');
        vector<string> stack{};
        for (const auto &part : parts)
        {
            if (part.empty() || part == ".")
            {
                continue;
            }

            if (part == "..")
            {
                if (!stack.empty())
                {
                    stack.pop_back();
                }
                continue;
            }

            stack.push_back(part);
        }
        if (stack.empty())
        {
            return "/";
        }
        ostringstream out{};
        for (const auto &p : stack)
        {
            out << '/' << p;
        }
        return out.str();
    }
};

int main()
{

    Solution solution;

    {
        const string path = "/home/";

        const string expected_output = "/home";
        const string output = solution.simplifyPath(path);

        Assert::equal(output, expected_output);
    }

    {
        const string path = "/home/foo";

        const string expected_output = "/home/foo";
        const string output = solution.simplifyPath(path);

        Assert::equal(output, expected_output);
    }

    {
        const string path = "/home/user/Documents/../Pictures";

        const string expected_output = "/home/user/Pictures";
        const string output = solution.simplifyPath(path);

        Assert::equal(output, expected_output);
    }

    {
        const string path = "/../";

        const string expected_output = "/";
        const string output = solution.simplifyPath(path);

        Assert::equal(output, expected_output);
    }

    {
        const string path = "/.../a/../b/c/../d/./";

        const string expected_output = "/.../b/d";
        const string output = solution.simplifyPath(path);

        Assert::equal(output, expected_output);
    }

    {

        const string path = "/a/./b/../../c/";

        const string expected_output = "/c";
        const string output = solution.simplifyPath(path);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
