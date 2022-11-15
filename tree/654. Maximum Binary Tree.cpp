/*
You are given an integer array nums with no duplicates. 
A maximum binary tree can be built recursively
 from nums using the following algorithm:
Create a root node whose value is the maximum value in nums.
Recursively build the left subtree 
on the subarray prefix to the left of the maximum value.
Recursively build the right subtree 
on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

題意:給一個樹數，返回一個最大樹
最大樹的構造根據定義
從數組裡找出最大的值，生成節點，做為root
root的左節點，在數組中，最大值的左半部份，繼續找出最大值生成左節點
root的左節點，在數組中，最大值的右半部份，繼續找出最大值生成右節點
反覆此邏輯，直到數組中每個值都構成了樹的節點

思路:建構一個dfs ，控制index 的開始和結束，來取用數組
完成定義的生成算法
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums,0,nums.size());
    }
    TreeNode* dfs(vector<int>& nums,int indexL,int indexR){
        if(indexL >= indexR)return nullptr;
        int maxIndex = indexL;
        for(int i=indexL;i<indexR;i++){
            if(nums[i] > nums[maxIndex])maxIndex = i;
        }
        TreeNode* node = new TreeNode( nums[maxIndex]);
        node->left =  dfs(nums,indexL,maxIndex);
        node->right =  dfs(nums,maxIndex+1,indexR);
        return node;
    }
};