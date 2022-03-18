/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.



Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 8
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
#include <stdio.h>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> dfs(int start, int end)
    {
        if (start > end)
            return {nullptr};
        vector<TreeNode *> ans;
        for (int i = start; i <= end; i++)
        {
            for (auto &leftTree : dfs(start, i - 1))
            {
                for (auto &rightTree : dfs(i + 1, end))
                {
                    TreeNode *node = new TreeNode(i, leftTree, rightTree);
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return dfs(1, n);
    }
};
// Runtime: 28 ms, faster than 36.41% of C++ online submissions for Unique Binary Search Trees II.
// Memory Usage: 16.6 MB, less than 9.25% of C++ online submissions for Unique Binary Search Trees II.


class Solution
{
    vector<vector<vector<TreeNode*>> > dp;
public:
    vector<TreeNode *> dfs(int start, int end)
    {
        if (start > end) return {nullptr}; 
        if(!dp[start][end].empty()) return dp[start][end]; 
        vector<TreeNode *> ans;
        for (int i = start; i <= end; i++)
        {
            for (auto &leftTree : dfs(start, i - 1))
            {
                for (auto &rightTree : dfs(i + 1, end))
                {
                    TreeNode *node = new TreeNode(i, leftTree, rightTree);
                    ans.push_back(node);
                }
            }
        }
        return dp[start][end]=ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        dp.resize(n+1,vector<vector<TreeNode*>>(n+1));    //2 记忆化添加得代码
        return dfs(1, n);
    }
};
// Runtime: 21 ms, faster than 60.71% of C++ online submissions for Unique Binary Search Trees II.
// Memory Usage: 12.3 MB, less than 94.17% of C++ online submissions for Unique Binary Search Trees II.