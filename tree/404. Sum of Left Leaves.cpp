/*
Given the root of a binary tree, 
return the sum of all left leaves.
A leaf is a node with no children. 
A left leaf is a leaf that is the left child of another node.

題意:把所有左節點葉子的val加總起來
思路:dfs 的時後加一個參數判斷是不是左節點，再判斷是不是葉子節點
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
    int sum;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,false);
        return sum;
    }
    void dfs(TreeNode* node,bool isLeft){
        if(node == nullptr)return;
        if(isLeft&&node->left==nullptr&&node->right==nullptr)sum = sum +node->val;
        dfs(node->left,true);
        dfs(node->right,false);
    }
};

// Runtime 10 ms Beats 31.70% Memory 13.4 MB Beats 82.5%