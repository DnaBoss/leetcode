/*
Given the root of a complete binary tree, 
return the number of the nodes in the tree.
According to Wikipedia, every level, 
except possibly the last, 
is completely filled in a complete binary tree, 
and all nodes in the last level are as far left as possible.
 It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1

題意:給一顆完全二元樹，計算它有多少節點
思路:dfs 只要能走到就+1，自底而上，先判斷非空，再判斷空，一行解決
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
    int countNodes(TreeNode* root) {
        return root?1+countNodes(root->left)+countNodes(root->right):0;
    }
};