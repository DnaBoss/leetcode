

/*
Given the root of a binary tree,
flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class
where the right child pointer points to the next node
in the list and the left child pointer is always null.
The "linked list" should be in the same order
as a pre-order traversal of the binary tree.
Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]

題意:把樹轉換成鏈結串列，必需使用原來的節點(不能new 新節點)
用 節點->right 當作 next

思路:
分成二種狀況
process:
1.如果root 有左節點
    step :
    a.則探索左節點的右側到底，
    這個節點會是左子樹最大的節點。
    b.把這個節點指向 root 的右子樹
    c.把根節點的右節點指向根節點的左節點
    d.把根節點的左節點指向NULL
    e.把根節點指向根節點的右節點
2.如果root沒有左節點
    a.把根節點指向根節點的右節點

重複process(1、2);
*/

// Runtime 8 ms Beats 76.78% Memory 12.8 MB Beats 37.4%
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
    void flatten(TreeNode* root) {
        while(root){
            TreeNode* cur = root->left;
            if(cur){
                while(cur->right)cur = cur->right;
                cur->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }

    }
};