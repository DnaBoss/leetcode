/*
Given a binary tree, determine if it is 
height-balanced

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true

題意:給一顆二元樹，判斷他是不是平衡二元樹
思路:dfs走訪節點
每一個節點都去判斷自已的左子樹和右子樹的高度差是否大於1
回傳自已的最大子樹深度 +1，給自已的父節點去做判斷
只要有任何一次大於1 全域布林變數 設為 false，預設為true

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
    bool ok = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ok;
    }
    int dfs(TreeNode* root){
        if(!root)return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(abs(l-r)>1){
            ok = false;
        }
        return 1+max(l,r);
    }
};

// Runtime 25 ms Beats 56.30% Memory 20.8 MB Beats 80.74%