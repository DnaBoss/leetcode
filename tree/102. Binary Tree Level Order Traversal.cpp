
/*
Given the root of a binary tree, 
return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).
題意：要你用一個二維容器，按照樹的level，把同level的值存在一個容器裡
返回一個二維容器 

思路：一個輔助函式，帶有當前節點、二維容器和level數
逐層去收集每一層的節點

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]

Example 3:
Input: root = []
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vvi;
        bfs(root,vvi,0);
        return vvi;
    }
    void bfs(TreeNode* node,vector<vector<int>> &vvi,int level){
        if(node == nullptr){
            return;
        }
        if(vvi.size() == level) vvi.push_back(vector<int>());
        vvi[level].push_back(node->val);
        bfs(node->left,vvi,level+1);
        bfs(node->right,vvi,level+1);
    }
};

//Runtime 4 ms Beats 80.61% Memory 13.3 MB Beats 12.83%