/*
Given the root of a binary tree, 
return the bottom-up level order traversal of its nodes' values.
 (i.e., from left to right, level by level from leaf to root).

 給一個二元樹的根節點，由下至上，按層數收集每個節點的值
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

思路，用一個二維的vector 由上而下的去收集
到底再reverse 就好了
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vvi ;
        bfs(root,vvi,0);
        reverse(vvi.begin(), vvi.end()); 
        return vvi;
    }
    void bfs(TreeNode* node,vector<vector<int>>& vvi,int level){
        if (node == nullptr) return;
        if (vvi.size() == level) vvi.push_back(vector<int>());
        vvi[level].push_back(node->val);
        bfs(node->left,vvi,level+1);
        bfs(node->right,vvi,level+1);
    }
};