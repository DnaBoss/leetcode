
/*
題目:https://leetcode.com/problems/permutations/
題意:給一串數字陣列，裡面的數字不重複，列出所有可能的排列
思路:
其實只要記得一件事，用一個陣列記錄哪個數字被用過，
backtracking的時後，true代表同樹支用過, false代表同層用過

*/
class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
    void backtracking(vector<int>& nums,vector<bool>& used){
        if(path.size() >= nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0;i< nums.size();i++){
            if(!used[i]){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums,used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};

// Runtime 3 ms Beats 86.6% Memory 8 MB Beats 38.83%