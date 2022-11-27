/*
題目：https://leetcode.com/problems/combination-sum-iii/description/
題意：
收集1~9的數字，到一個容器（1維vec），
一個容器最長可以收集k個，若這k個元素恰好等於n
將此容器放進解答的容器（2維vec）中
*/

class Solution {
public:
    vector<vector<int>> vvi;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>vi;
        backtracking(k,n,1,0);
        return vvi;
    }
    void backtracking(int k,int n,int start,int sum){
        int size = path.size();
        // cout << size << endl;
        if(size == k){
            if(sum == n){
                vvi.push_back(path);
            }
            return;
        }
        for(int i = start;i<=9;i++){
            // cout << i << endl;
            path.push_back(i);
            backtracking(k,n,i+1,sum+i);
            path.pop_back();
        }
    }
};

// Runtime 0 ms Beats 100% Memory 6.4 MB Beats 61.2%