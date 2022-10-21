/*
A path in a binary tree is a sequence of nodes 
where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, 
return the maximum path sum of any non-empty path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
難度:hard
題意:
找出一條路徑合最大的路徑，
每個節點不能走過一次，
不一定要巡訪過根節點

思路:自上而下巡訪所有子樹(節點)
每一個子樹能提供給自已的父節點最大的值是
自已 + (自已的左子樹能提供的最大值 or 自已的右子樹能提供的最大值 or 0)
如果自身是根節點，全樹的最大值可能有六種情況 
1.自身
2.自身 + 左子樹
3.自身 + 右子樹
4.自身+左子樹+右子樹
5.左子樹
6.右子樹
每往下一層子樹計算時，去比較 max 跟 4 的情況，
即可找出最大值 
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
    int max = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        dfs(root);
        return max;
    };
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int maxLeft = dfs(root->left);
        int maxRight = dfs(root->right);
        max = std::max(max,root->val+ std::max(0,maxLeft) + std::max(0,maxRight)) ;
        int sum = root->val +std::max(0,std::max(maxLeft,maxRight)) ;
        return sum;
    };
};

// Runtime 39 ms Beats 71.68%

