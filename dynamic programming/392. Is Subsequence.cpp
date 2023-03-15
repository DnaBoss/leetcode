/**
題目:https://leetcode.com/problems/is-subsequence/
題意:回傳 s 是否為 t 的子序序
思路:
1. 雙指針: 二個迴圈，第一個迴圈歷遍s，
看能不能在t中找到s的字元，
找到的話就把下次歷遍t的下標 改為 找到的 + 1，
如果任何一個s的字元無法在t中被找到，則返回false
當s中的最後一個字元也被找到了，返回true

2. 動態規畫:dp[i][j] 表 s[i] 跟 t[j] 的最長子序列
如果 dp[s長度][t長度] = s 的長度
則返回true
 * 
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m == 0)return true;
        int startIndex = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = startIndex; j < n;j++)
            {
                if(s[i] == t[j]){
                    startIndex = j + 1;
                    if(i == m -1){
                        return true;
                    }
                    break;
                }
                if(j == n-1){
                    return false;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n;j++)
            {
                if(s[i -1 ] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    // 這裡不應該是 max(dp[i-1][j],dp[i][j-1]) 因為是要求 s 是否是 t 的子序列，不是求最大公共子序列
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if(dp[m][n] == m){
            return true;
        }
        return false;
    }
};