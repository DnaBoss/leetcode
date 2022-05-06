/*322. Coin Change
Medium

11015

267

Add to List

Share
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
*/
#include <math.h>
class Solution
{
public:
   int coinChange(vector<int> &coins, int amount)
   {
      int  coinsSize = coins.size();
      int *dp = new int[amount + 1];
      dp[0] = 0;
      for (int i = 1; i <= amount; ++i)
      {
         dp[i] = INT_MAX;
         for (int j = 0; j < coinsSize; ++j)
         {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX)
            {
               dp[i] = std::min(dp[i - coins[j]] + 1, dp[i]);
            }
         }
      }
      
      if (dp[amount] == INT_MAX)
      {
         dp[amount] = -1;
      }
      return dp[amount];
   }
};

// Runtime: 88 ms, faster than 75.48% of C++ online submissions for Coin Change.
// Memory Usage: 14.5 MB, less than 55.05% of C++ online submissions for Coin Change.