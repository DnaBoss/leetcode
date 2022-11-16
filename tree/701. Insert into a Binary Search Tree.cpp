/*
You are given the root node of a binary search tree (BST) 
and a value to insert into the tree. 
Return the root node of the BST after the insertion. 
It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist
multiple valid ways for the insertion, 
as long as the tree remains a BST 
after insertion. You can return any of them.

題意:給一個二元搜尋樹，插入一個值，返回一個插入值的BST
思路:
如果值比當前節點小，往左樹找地方插，如果沒左節點，直接指成左節點
如果值比當前節點大，往右樹找地方插，如果沒右節點，直接指成右節點

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        if(root->val > val){
            if(root->left){
                insertIntoBST(root->left,val);
            }else{
                root->left =  new TreeNode(val);
            }
        }else{
            if(root->right){
                insertIntoBST(root->right,val);
            }else{
                root->right =  new TreeNode(val);
            }
        }
        return root;
    }
};

// Runtime 98 ms Beats 93.32% Memory 57 MB Beats 49.3%