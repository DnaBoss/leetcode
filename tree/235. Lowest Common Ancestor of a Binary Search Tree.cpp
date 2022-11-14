/*
Given a binary search tree (BST), 
find the lowest common ancestor (LCA) node 
of two given nodes in the BST.
According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined 
between two nodes p and q as the lowest node 
in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2
題意:給一顆樹，和任樹中的二個不同的節點，找出最近的共同的祖先
一個節點可以是自已的祖先
思路:
每個節點有二種可能 1 是LCA 2 不是 LCA
(廢話)
是LCA的情況下，有二種可能，
a.節點自身是LCA 
    如果 自身是LCA，
    代表左子樹或右子樹其中一個子樹包含目標節點
    以及自身就是目標節點
b.節點自身不是LCA
    二個目標，必需恰好一個在左子樹、一個在右子樹
所以一共有三點要判斷
1.首先判斷自已是不是目標節點
2.判斷目標節點在不在左子樹
3.判斷目標節點在不在右子樹

如果自身不是 LCA 的話，那就告知自已的父親，
目標有沒有在自已或自已的子樹之中

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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