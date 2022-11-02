/*
Given the root of a binary tree, i
imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.
題意：給一個二元樹的　root, 自root開始，把每一個節點的右節點收集到一個容器裡
我本來以為只要一直dfs 右節點就好，但其實是要前序歷遍，把每一層的最後一個節點值收集起來
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int> v ={};
        if(root!= nullptr) q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(i==size-1)v.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return v;
    }
};

// Runtime 10 ms Beats 24.21% Memory 12.2 MB Beats 10.53%