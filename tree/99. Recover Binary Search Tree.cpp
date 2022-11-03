/*
You are given the root of a binary search tree (BST),
where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.

題意:一個二元搜尋樹中的二個節點錯置了，回復它該有的樣子
思路:
中序遍歷，則預期會由小走到大

如果前一個節點的值大於當前節點，
則「前一個」節點便是第一個錯置節點。

第二次再遇到前一個節點大於當前節點的情況時
則「當前」節點是第二個錯置節點。
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
    TreeNode *node1,*node2,*pre;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
    void inorder(TreeNode* node){
        if(node==nullptr)return;
        inorder(node->left);
        if(pre!=nullptr&&pre->val > node->val){
            if(node1==nullptr) node1 = pre;
            node2 = node;
        }
        pre = node;
        inorder(node->right);
    }
};

// Runtime 71 ms Beats 34.48% Memory 57.9 MB Beats 71.21%