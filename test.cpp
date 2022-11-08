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

#include<vector>
#include <climits>
using namespace std;
int main(){
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
    auto s = new Solution();
    vector<int> number = {1, 3, 7};
    int x = s->coinChange(number,23);
}

// Runtime: 88 ms, faster than 75.48% of C++ online submissions for Coin Change.
// Memory Usage: 14.5 MB, less than 55.05% of C++ online submissions for Coin Change.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
       if(!root->left&&!root->right)return root->val;
       int left = root->left?dfs(root->left,root->val*10):0;
       int right = root->right?dfs(root->right,root->val*10):0;
       return left + right;
    }
    int dfs(TreeNode* node,int sum){
        sum = sum + node->val;
        if(!node->left&&!node->right) return sum;
        int left =node->left? dfs(node->left,sum*10):sum;
        int right =node->right? dfs(node->right,sum*10):sum;
        return left + right;
    }
};

[4,9,0,null,1]