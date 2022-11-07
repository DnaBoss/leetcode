/*
Given the root of a binary tree, 
return an array of the largest value 
in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]

題意：給一顆樹，找出樹中每一層最大的數字
思路　bfs 每一層去下比數字大小，要注意會有負數
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
    vector<int> largesNums;
    vector<int> largestValues(TreeNode* root) {
        if(!root)return largesNums;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int maxNum = INT_MIN;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val > maxNum) maxNum = node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            largesNums.emplace_back(maxNum);
        }
        return largesNums;
    }
};



// Runtime 36 ms Beats 11.71% Memory 22.2 MB Beats 70.67%