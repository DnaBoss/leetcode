
/*
Given the root of a binary tree, 
return all root-to-leaf paths in any order.
A leaf is a node with no children.

題意:以指定格式回傳根節點到葉節點的路徑(以節點的值+ "->"為表示)
思路:以dfs 走到葉節點，
用to_string把數字轉字串,
其它沒什麼特別好說的，
 
Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]
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
    vector<string> v;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return v;
    }
    void dfs(TreeNode* node,string path){
        if(!node)return;
        path = path + to_string(node->val);
        if(!node->left&&!node->right){
            v.emplace_back(path);
            return;
        }
        dfs(node->left,path + "->");
        dfs(node->right,path + "->");
    }
};
// Runtime 7 ms Beats 62.57% Memory 13.6 MB Beats 27.94%