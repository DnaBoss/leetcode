/*
You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.
You need to merge the two trees into a new binary tree. 
The merge rule is that if two nodes overlap,
 then sum node values up as the new value of the merged node. 
 Otherwise, the NOT null node will be used as the node of the new tree.
Return the merged tree.
Note: The merging process must start from the root nodes of both trees.
Example 1:
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:
Input: root1 = [1], root2 = [1,2]
Output: [2,2]

題意:把二個樹合併成一顆，新的樹的val 
是二顆樹相同位置節點的值相加

思路:用嘴巴念一次
新的樹的node，是樹1的node + 樹2的node
新的樹的node->left是樹1的 node->left + 樹2的 node->left
新的樹的node->right 是樹1的 node->right + 樹2的 node->right
recursive 結束。

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return addNode(root1,root2);
    }

     TreeNode* addNode(TreeNode* node1,TreeNode* node2){
        if (!node1) return node2;
        if (!node2) return node1; 
        node1->val = node1->val+node2->val;
        node1->left = addNode(node1->left,node2->left);
        node1->right = addNode(node1->right,node2->right);
        return node1;
    }
};