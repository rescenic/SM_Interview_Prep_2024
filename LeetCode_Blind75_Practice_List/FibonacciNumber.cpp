#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Reference: https://math.libretexts.org/Bookshelves/Applied_Mathematics/Book%3A_College_Mathematics_for_Everyday_Life_(Inigo_et_al)/10%3A_Geometric_Symmetry_and_the_Golden_Ratio/10.04%3A_Fibonacci_Numbers_and_the_Golden_Ratio#:~:text=The%20number%20that%20these%20ratios,this%20number%20in%20Binet%27s%20formula.&text=The%20Golden%20Ratio%20has%20the,for%20a%20variety%20of%20reasons.

// TC: O(1)
// SC: O(1)

class Solution1
{
public:
  int fib(int N)
  {
    double phi = round_d((1 + pow(5, 0.5)) / 2, 6);
    return round((pow(phi, N) - pow(-phi, -N)) / (pow(5, 0.5)));
  }

private:
  // Rounds a value to n decimal places according to the precision, using the rounding rule of natural numbers
  double round_d(double var, int precision = 2)
  {
    // if precision = 3 then
    // 37.66666 * 10^3 =37666.66
    // 37666.66 + .5 =37667.1    for rounding off value
    // then type cast to <int> so value is 37667
    // then divided by 10^3 so the value converted into 37.667
    if (precision < 0)
      precision = 0;
    double value = (var >= 0) ? (int)(var * pow(10, precision) + .5) : (int)(var * pow(10, precision) - .5);
    return value / pow(10, precision);
  }
};

// Time:  O(logn)
// Space: O(1)

class Solution2
{
public:
  int fib(int N)
  {
    vector<vector<int>> T = {{1, 1},
                             {1, 0}};
    return matrixMult({{1, 0}}, matrixExpo(T, N))[0][1]; // [a1, a0] * T^N
  }

private:
  vector<vector<int>> matrixExpo(const vector<vector<int>> &A, int pow)
  {
    vector<vector<int>> result(A.size(), vector<int>(A.size()));
    vector<vector<int>> A_exp(A);
    for (int i = 0; i < A.size(); ++i)
    {
      result[i][i] = 1;
    }
    while (pow)
    {
      if (pow % 2 == 1)
      {
        result = matrixMult(result, A_exp);
      }
      A_exp = matrixMult(A_exp, A_exp);
      pow /= 2;
    }
    return result;
  }

  vector<vector<int>> matrixMult(const vector<vector<int>> &A, const vector<vector<int>> &B)
  {
    vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); ++i)
    {
      for (int j = 0; j < B[0].size(); ++j)
      {
        int64_t entry = 0;
        for (int k = 0; k < B.size(); ++k)
        {
          entry = (static_cast<int64_t>(A[i][k]) * B[k][j] + entry);
        }
        result[i][j] = static_cast<int>(entry);
      }
    }
    return result;
  }
};

// Time:  O(n)
// Space: O(1)
class Solution3
{
public:
  int fib(int N)
  {
    vector<int> dp(3, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
      dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
    }
    return dp[N % 3];
  }
};
