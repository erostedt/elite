/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth
characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces '
' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not
divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.


Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be
left-justified instead of fully-justified. Note that the second line is also left-justified because it contains only one
word. Example 3:

Input: words =
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],
maxWidth = 20 Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]


Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
*/

#include <algorithm>
#include <iostream>
#include <span>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    size_t find_fit(span<string> words, int max_width)
    {
        size_t width = 0;
        for (size_t i = 0; i < words.size(); ++i)
        {
            width += words[i].size();
            if (width > max_width)
            {
                return i;
            }
            width += 1;
        }
        return words.size();
    }

    void left_justify(span<char> view, span<string> words)
    {
        for_each(begin(words), end(words), [&](const string &word) {
            copy(begin(word), end(word), begin(view));
            view = view.subspan(word.size() + 1);
        });
    }

    void right_justify(span<char> view, span<string> words)
    {
        for_each(rbegin(words), rend(words), [&](const string &word) {
            copy(rbegin(word), rend(word), rbegin(view));
            view = view.subspan(0, view.size() - word.size() - 1);
        });
    }

    void evenly_justify(span<char> view, span<string> words)
    {
        if (words.empty())
        {
            return;
        }

        size_t char_count = 0;
        for (const auto &word : words)
        {
            char_count += word.size();
        }

        size_t gaps = words.size() + 1;
        size_t total_spaces = size(view) - char_count;
        size_t space_per_gap = total_spaces / gaps;
        size_t extra_spaces = total_spaces % gaps;

        size_t pos = 0;
        for (size_t i = 0; i < size(words); ++i)
        {
            pos += space_per_gap + (i < extra_spaces ? 1 : 0);
            copy(words[i].begin(), words[i].end(), view.begin() + pos);
            pos += words[i].size();
        }
    }

    string justify(span<string> words, int max_width)
    {
        string result(max_width, ' ');
        span<char> view = result;
        left_justify(view, words.first(1));
        if (words.size() == 1)
        {
            return result;
        }

        auto middle_words = span(next(begin(words)), prev(end(words)));
        span<char> middle(begin(view) + words.front().size(), end(view) - words.back().size());
        evenly_justify(middle, middle_words);

        right_justify(view.last(words.back().size() + 1), words.last(1));

        return result;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result{};
        span<string> remaining = words;
        vector<size_t> splits{};

        while (!remaining.empty())
        {
            const size_t i = find_fit(remaining, maxWidth);
            remaining = remaining.subspan(i);
            splits.push_back(i);
        }

        remaining = words;
        for (size_t k = 0; k < splits.size() - 1; ++k)
        {
            const size_t i = splits.at(k);
            const auto res = justify(remaining.first(i), maxWidth);
            remaining = remaining.subspan(i);
            result.push_back(res);
        }

        string last(maxWidth, ' ');
        span<char> view = last;
        left_justify(view, remaining);
        result.push_back(last);
        return result;
    }
};

int main()
{
    Solution solution;
    {

        vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
        const int maxWidth = 16;

        vector<string> expected_output = {"This    is    an", "example  of text", "justification.  "};
        const vector<string> output = solution.fullJustify(words, maxWidth);

        Assert::equals(output, expected_output);
    }
    {
        vector<string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
        const int maxWidth = 16;

        vector<string> expected_output = {"What   must   be", "acknowledgment  ", "shall be        "};
        const vector<string> output = solution.fullJustify(words, maxWidth);

        Assert::equals(output, expected_output);
    }
    {
        std::vector<std::string> words = {"Science", "is", "what",       "we",   "understand", "well",
                                          "enough",  "to", "explain",    "to",   "a",          "computer.",
                                          "Art",     "is", "everything", "else", "we",         "do"};
        const int maxWidth = 20;

        std::vector<std::string> expected_output = {"Science  is  what we", "understand      well",
                                                    "enough to explain to", "a  computer.  Art is",
                                                    "everything  else  we", "do                  "};
        const std::vector<std::string> output = solution.fullJustify(words, maxWidth);

        Assert::equals(output, expected_output);
    }
    std::cout << "All passed" << std::endl;
}
