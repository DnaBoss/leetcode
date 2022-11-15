/*
Given a root node reference of a BST and a key, 
delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.
Basically, the deletion 
can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
 
Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. 
So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], 
shown in the above BST.
Please notice that another valid answer 
is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []

題意:給一顆樹和一個值，刪除對應值的節點
思路:key 值
大於當前節點值，去右子樹刪，返回值即為當前節點的右節點
小於則去左子樹刪，返回值即為當前節點的左節點
等於的話
1.沒有左子樹 => 返回右子樹
2.沒有右子樹 => 返回左子樹
3.有左子樹也有右子樹 => 
    a.找到右子樹的最左節點
    b.把最左節點向向root的左節點
    c.把root指向root的右節點
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(key>root->val)root->right = deleteNode(root->right,key);
        if(key<root->val)root->left = deleteNode(root->left,key);
        if(key==root->val){
            if(!root->left)return root->right;
            if(!root->right)return root->left;
            TreeNode* node = root->right;
            while(node->left)node=node->left;
            node->left = root->left;
            root = root->right;
        };
        return root;
    }
};