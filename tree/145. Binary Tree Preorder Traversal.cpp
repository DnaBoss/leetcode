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
 就後序歷遍，沒什麼好講的
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         help(root);
         return res;
    }
    void help(TreeNode* root){
        if(root){
            help(root->left);
            help(root->right);
            res.push_back(root->val);
        }
        return;
    }
private:
    vector<int> res;
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 8.6 MB, less than 13.63% of C++ online submissions for Binary Tree Postorder Traversal.
