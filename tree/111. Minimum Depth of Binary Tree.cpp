/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes 
along the shortest path 
from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

題意:找出一顆樹，從根節點到最近的一個葉節點的深度
思路:
用bfs一層層找，只要當前這層出現葉節點就回傳深度，每往下一層深度加1

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5*/
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(!node->left&&!node->right)return level;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            level++;
        };
        return level;
    };
};
// Runtime 592 ms Beats 21.48% Memory 144.7 MB Beats 44.91%