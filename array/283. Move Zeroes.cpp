/*
題目:https://leetcode.com/problems/move-zeroes/
題意:把一個整數，拆分成n個數的和，使其積為最大，回傳這個最大的積
思路:dp，拆成 二個數，及以上的情況能得到的最大的積

 */

class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3;i <= n; i++){
            for(int j = 1;j <=i/2;j++){
              dp[i] = max(dp[i],max(j*dp[i-j],j*(i-j)));
            }
        }

        return dp[n];


    }
};