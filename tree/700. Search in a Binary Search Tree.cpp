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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <stdio.h>
#include <vector>

using namespace std;
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
            return root;
        return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};

// Runtime: 28 ms, faster than 99.59% of C++ online submissions for Search in a Binary Search Tree.
// Memory Usage: 34.9 MB, less than 24.62% of C++ online submissions for Search in a Binary Search Tree.