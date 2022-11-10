/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. 
hat means the first house is the neighbor of the last one. Meanwhile,
adjacent houses have a security system connected,
and it will automatically contact 
the police if two adjacent houses were broken into on the same night.

Given an integer array nums 
representing the amount of money of each house, 
return the maximum amount of 
money you can rob tonight without alerting the police.

 

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3

題意:你是土匪，你要搶劫一個陣列，陣列內的元素不能連續搶
頭尾只能選一個搶
問最多能搶到多少

思路:每個元素有拿和不拿的差別，記路每個index，拿和不拿會有多少錢
拿:元素自身的值 + 前一個元素不拿的和
不拿:max (前一個元素拿,前一個元素不拿)

然後再分 拿頭不拿尾 跟 拿尾不拿頭 二種裝況，比大小
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==0)return 0;
        if(size==1)return nums[0];
        vector<vector<int>> status1;
        vector<vector<int>> status2;
        status1.push_back({0,nums[0]});
        status2.push_back({0,nums[1]});
        status2.push_back({0,nums[1]});
        for(int i = 1;i<size-1;i++){
            int notRob1 = max(status1[i-1][0],status1[i-1][1]);
            int okRob1 = nums[i]+status1[i-1][0];
            status1.push_back({notRob1,okRob1});
        }
        for(int i = 2;i<size;i++){
            int notRob2 = max(status2[i-1][0],status2[i-1][1]);
            int okRob2 = nums[i]+status2[i-1][0];
            status2.push_back({notRob2,okRob2});
        }
        int max1 = max(status1[size-2][0],status1[size-2][1]);
        int max2 = max(status2[size-1][0],status2[size-1][1]);
        return max(max1,max2);
    }
};
// Runtime 7 ms Beats 15.5% Memory 8.3 MB Beats 5.32%