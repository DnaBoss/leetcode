/*
題目:https://leetcode.com/problems/min-cost-climbing-stairs/
題意:爬樓題，從0階或1階開始爬，cost[i] 代表從 從第 i 階開始爬需要的代價，問爬到最頂樓的最小花費
思路: dp 代表 爬到 第 i 階的最小花費 
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if(size <= 1)return cost[0];
        vector<int>dp(size + 1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2;i <= size;i++){
            dp[i] = min(dp[i - 1] + cost[i - 1],dp[i - 2] + cost[i - 2]);
        }
        return dp[size];
    }
};