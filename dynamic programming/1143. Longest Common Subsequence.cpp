/*
題目:https://leetcode.com/problems/longest-common-subsequence/
題意:返回二個字串的最長公共子序列
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
            int m = text1.size();
            int n = text2.size();
            // dp 的定義，dp[i][j] 即，text1 從0到第i個字 跟 text2從0到第j個字  的最長公共子序列
            // 因為要跑到第 m 跟 n ，所以數組要開 m+1 跟 n+1
            vector<vector<int>>dp(m+1,vector<int>(n+1,0));
            // 下標0的二個字元會不會一樣，要從第1個字元來往回判斷，所以要從1開始跑，從0就會出錯
            for(int i = 1; i <= m;i++){
                for(int j = 1; j <= n;j++){
                    if(text1[i-1] == text2[j-1]){
                        dp[i][j] = dp[i-1][j-1] + 1;
                        // std::cout << "i = " << i << ", j= " << j << ", dp[i][j] = " << dp[i][j]  << std::endl; 印出來看就懂了
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            return dp[m][n];
    }
};