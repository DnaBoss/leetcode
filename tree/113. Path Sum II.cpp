/*
Given the root of a binary tree 
and an integer targetSum, 
return all root-to-leaf paths 
where the sum of the node values 
in the path equals targetSum. 
Each path should be returned as a list of the node values,
not node references.
A root-to-leaf path is a path starting from the root 
and ending at any leaf node. A leaf is a node with no children.

題意:給定一個根節點和一個目標數字，
找出每一條從根節點到葉節點的路徑和，
剛好等於目標數字的路徑
 
思路:
就dfs帶者數字減去節點的值，一直往下找，
直到目標數字被減光，而且剛好又是又節點，就把路徑存在容器內

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []
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
    vector<vector<int>> vv;
    vector<int> path;
    void dfs(TreeNode* node, int targetSum){
        if(node == nullptr)return;
        path.emplace_back(node->val);
        targetSum -= node->val;
        if (!node->left && !node->right && targetSum == 0)vv.emplace_back(path);
        dfs(node->left, targetSum);
        dfs(node->right, targetSum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return vv;
    }
};
// Runtime 25 ms Beats 37.33% Memory 19.8 MB Beats 91.90%