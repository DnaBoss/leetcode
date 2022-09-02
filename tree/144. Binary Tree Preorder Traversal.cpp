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
    就前序歷遍，沒有什麼好講的
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
         help(root);
         return res;
    }
    void help(TreeNode* root){
        if(root){
            res.push_back(root->val);
            help(root->left);
            help(root->right);
        }
        return;
    }
private:
    vector<int> res;
};