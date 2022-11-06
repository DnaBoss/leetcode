/*
Given the root of a binary tree 
and an integer targetSum, 
return true if the tree has a root-to-leaf path 
such that adding up all the values 
along the path equals targetSum.

A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Example 3:
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

題意:
給一顆樹，
判斷是否存在一條從根節點到葉節的路徑和，
加起來剛好等於給定的目標數字
思路:dfs 跑完就是，沒什麼好說的
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
    bool isHas;
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return isHas;
    }
    void dfs(TreeNode* node, int targetSum){
        if(!node)return;
        targetSum = targetSum - node->val;
        if(!node->left&&!node->right&&targetSum==0)isHas = true;
        dfs(node->left,targetSum);
        dfs(node->right,targetSum);
    }
};

// Runtime 19 ms Beats 65.89% Memory 21.3 MB Beats 74.5%