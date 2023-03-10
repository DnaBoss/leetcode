/**
題目:https://leetcode.com/problems/fibonacci-number/
題意:求費波那希
思路:動態規劃 
*/

class Solution {
public:
    int fib(int n) {
        if (n < 1) return 0;
        vector<int>dp(n+1);
        dp[0] = 0; 
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};