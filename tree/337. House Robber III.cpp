/*
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.
Besides the root, each house has one and only one parent house. 
After a tour, 
the smart thief realized that 
all houses in this place form a binary tree. 
It will automatically contact the police 
if two directly-linked houses were broken into on the same night.
Given the root of the binary tree, 
return the maximum amount of money 
the thief can rob without alerting the police.
Example 1:
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money 
the thief can rob = 3 + 3 + 1 = 7.

Example 2:
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money 
the thief can rob = 4 + 5 = 9.

題意:土匪要打劫一顆樹上的節點，土匪不能打連續打劫二個相連的節點
問土匪最多可以在這顆樹上打劫到多少錢
錢 即 節點的 val

思路:
每個節點有二種狀態，被打劫和不被打劫
不被打劫時，此節點的子樹，所能提供的最多金額為 左子樹能提供的最多金額+右子樹能提供的最多金額
被打劫時，此節點的子樹，所能提供的最多金額為 左子樹不被打劫時提供的金額+右子樹不被打劫時提供的金額
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
    int rob(TreeNode* root) {
        auto self = dfs(root);
        return max(self[0],self[1]);
    }
    vector<int>dfs(TreeNode* root){
        if(!root)return {0,0};
        auto lT = dfs(root->left);
        auto rT = dfs(root->right);
        int noRob = max(lT[0], lT[1]) + max(rT[0], rT[1]);
        int okRob = root->val+lT[0]+rT[0];
        return {noRob,okRob};
    }
};

// Runtime 45 ms Beats 27.44% Memory 31.9 MB Beats 8.27%