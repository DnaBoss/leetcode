//
// Created by mathe on 2022/7/22.
//
main(){
    class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if(!root){
                return root;
            }
            TreeNode* left = invertTree(root->left);
            TreeNode* right = invertTree(root->right);
            root->left = right;
            root->right = left;
            return root;
        }
    };
    auto s = new Solution();
    s->invertTree([4,2,7,1,3,6,9]);

}