/*
就是照抄 235 題
*/
class Solution {
public:
    TreeNode* ancestor;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ancestor = root;
        dfs(root,p,q);
        return ancestor;
    }
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node)return false;
        bool isSelfAncestor = node->val == p->val ||node->val == q->val ;
        bool isInL = dfs(node->left,p,q);
        bool isInR = dfs(node->right,p,q);
        if(isInL&&isInR||isSelfAncestor&&isInL||isSelfAncestor&&isInR){
            ancestor = node;
        }
        return isSelfAncestor||isInL||isInR;
    }
};