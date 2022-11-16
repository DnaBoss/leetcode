/*
Given the root of a binary tree, 
return the leftmost value in the last row of the tree.

Example 1:
Input: root = [2,1,3]
Output: 1

Example 2:
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7

題意:找出最深、最左的葉節點
思路:用bfs，每一次for 都記錄第一節點的值，最後離開的時後記錄的就會是最深一層的最左節點值
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int leftmost;
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(i==0){
                    leftmost = node->val;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return leftmost;
    }
};
// Runtime 23 ms Beats 59.66% Memory 21.7 MB Beats 63.12%