/*
題目:https://leetcode.com/problems/subsets-ii/
題意:給一個整數集陣列，裡面可能有重複的數字，請返回所有可能的子集，且不能有重複的子集
*/
class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtracking(nums,0,used);
        return result;
    }
    void backtracking(vector<int>& nums,int startIndex,vector<bool>& used){
        int size = nums.size();
        result.push_back(path);
        for(int i = startIndex;i < size;i++){
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums,i+1,used);
            path.pop_back();
            used[i] = false;
        }
    }
};