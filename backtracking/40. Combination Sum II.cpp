/*
題目：https://leetcode.com/problems/combination-sum-ii/description/
題意：給定一維容器，裡面放的是數字，以及給定一個目標數
求，所有可以恰好加起來等於目標數的組合
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,used,0,0);
        return result;
    }
    void backtracking(vector<int>& candidates, int target,vector<bool> used, int sum,int startIndex){

        if(sum == target){
            result.push_back(path);
            return;
        }
        int size = candidates.size();
        for(int i = startIndex;i < size && sum + candidates[i] <= target;i++){
            if(i>0 && candidates[i] == candidates[i-1] && used[i-1] == false){
                continue;
            }
            used[i] = true;
            path.push_back(candidates[i]);
            backtracking(candidates,target,used,sum + candidates[i],i+1);
            path.pop_back();
            used[i] = false;
        }
    }
};