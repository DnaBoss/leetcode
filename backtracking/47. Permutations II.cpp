/*
題目：https://leetcode.com/problems/permutations-ii/description/
題意：給一個一維容器，裡面放數字，數字可能重覆，給出所有數字的排列
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtracking(nums,used);
        return result;
    }
    void backtracking(vector<int>& nums,vector<bool> used){
        int size = nums.size();
        if(path.size() == size){
            result.push_back(path);
            return;
        }
        
        for(int i = 0; i < size ; i++){
            // used[i]  == true 代表　nums[i]　這個數字，在　同一「分支」中被使用過
            // used[i]  == false 代表　nums[i]　這個數字，在　同一「層」中被使用過
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
                continue;
            }
            if (used[i] == false) {
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums,used);
            used[i] = false;
            path.pop_back();
            }
        }
    }
};
// Runtime 35 ms Beats 31.43% Memory 9.7 MB Beats 43.94%