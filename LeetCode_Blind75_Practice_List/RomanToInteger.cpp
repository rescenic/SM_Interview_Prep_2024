// Time:  O(n)
// Space: O(1)

#include <vector>
#include <string>
#include <unordered_map>
#include <numeric> //accumulate

using namespace std;

class Solution1
{
public:
  Solution1() = default;
  ~Solution1() = default;
  Solution1(const Solution1&) = delete;

  int romanToInt(string s)
  {
    unordered_map<char, int> numeral_map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    int decimal = 0;
    for (int i = 0; i < s.length(); ++i)
    {
      if (i > 0 && numeral_map[s[i]] > numeral_map[s[i - 1]])
      {
        decimal += numeral_map[s[i]] - 2 * numeral_map[s[i - 1]];
      }
      else
      {
        decimal += numeral_map[s[i]];
      }
    }
    return decimal;
  }
};

// Time:  O(n)
// Space: O(1)
class Solution2
{
public:
  Solution2() = default;
  ~Solution2() = default;
  Solution2(const Solution2&) = delete;

  int romanToInt(string s)
  {
    unordered_map<char, int> numeral_map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    return accumulate(s.crbegin(), s.crend(), 0,
                      [&numeral_map](int sum, char c)
                      {
                        return sum += ((numeral_map[c] * 5 <= sum) ? -numeral_map[c] : numeral_map[c]);
                      });
  }
};

int main()
{
  return 0;
}
