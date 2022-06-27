/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
Example 1:
Input: n = 3 ,Output: 5

Example 2:
Input: n = 1 ,Output: 1
Constraints:1 <= n <= 19
*/
class Solution {
public:
    int numTrees(int n) {
        int* dp = new int[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i = 2;i<=n;i++){
            dp[i] = 0; // 用 vector<int> 或 int[] 就不用在這裡給0值
            for(int j=0;j<i;j++){
                // 當i是root 時，把i左邊可能的排列跟i的右邊可能有的排列 *完再 sum，就是答案
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};