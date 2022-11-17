/*
Given the root of a Binary Search Tree (BST), 
return the minimum absolute difference 
between the values of any two different nodes in the tree.
題意:找出一顆BST中，任意二節點的最小差絕對值
思路:如果今天不是 BST的話，那就必需把每節點先固定，
然後去計算跟所有其它節點的差
但BST是有序的，所以只要用中序遍歷，記錄前一個節點
求前一個節點跟當前節點的差，並記錄在全域變數即可
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
    int min = INT_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return min;
    }
    void dfs(TreeNode* node){
        if(!node)return;
        dfs(node->left);
        if(pre!=nullptr){
            int target = abs(node->val-pre->val);
            if(target<min)min = target;
        }
        pre = node;
        dfs(node->right);
    }
};