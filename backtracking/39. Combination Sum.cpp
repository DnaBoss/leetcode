
/*
題目：https://leetcode.com/problems/combination-sum/description/
題意：給定一個一維向量 裡面放的是數字，每一個數字都可以不限次數的取用
請組合出目標數字，並將此一組合，放進一個二維向量
*/
class Solution {
public:
    vector<vector<int>>vvi;
    vector<int>path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return  vvi;
    }
    void backtracking(vector<int>& candidates, int target,int sum,int startIndex){
        if(sum > target){
            return;
        }
        if(sum == target){
            vvi.push_back(path);
            return;
        }
        int size = candidates.size();
        for(int i = startIndex;i < size;i++){
            int num = candidates[i];
            path.push_back(num);
            backtracking(candidates,target,sum+num,i);
            path.pop_back();
        }
    }
};

// Runtime 13 ms Beats 53.32% Memory 11 MB Beats 54.41%