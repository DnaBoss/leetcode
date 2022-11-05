/*
Given the root of a binary tree and an integer targetSum, 
return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, 
but it must go downwards 
(i.e., traveling only from parent nodes to child nodes).
題意:給一顆樹和一個目標數字
只能由上往下走，任何二個路徑的和，可以跟目標數字一樣，就算一條合格的路徑
找出所有合格路徑

思路:dfs 每到下一個節點，再以下一個節點為新樹的root，從新從下找
注意點:要把重新往下找的路徑和原來的如徑做分隔，否則會重複計算
還有就是題目有一題測資會出超大的數字，dfs 的累加數，要用long long 宣告

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
    int pathAmount = 0; 
    int sum;
    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        dfs(root,0,false);
        return pathAmount;
    }
    void dfs(TreeNode* node, long long targetSum,bool flag){
        if(!node)return;
        targetSum = targetSum + node->val;
        if(targetSum==sum)pathAmount=pathAmount+1;
        dfs(node->left,targetSum,true);
        dfs(node->right,targetSum,true);
        if(flag)return;
        dfs(node->left,0,false);
        dfs(node->right,0,false);
    }
};
// Runtime 78 ms Beats 17.56% Memory 16 MB Beats 67.19%