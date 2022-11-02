/*
Given the root of a binary tree, 
return the average value of the nodes on each level in the form of an array.
Answers within 10-5 of the actual answer will be accepted.

題意：用一個一維容器，收集每一層所有節點的值的平均數
思路：bfs 收集後返還，記得要用 double 沒什麼好說的
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> v;
        if(root!=nullptr)q.push(root);
        while(!q.empty()){
            int size = q.size();
            double sum = 0;
            for(int i = 0; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();
                sum = sum + node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            v.push_back(sum/size);
        }
        return v;
    }
};