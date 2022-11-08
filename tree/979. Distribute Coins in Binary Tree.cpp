/*
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

Example 1:
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, 
we move one coin to its left child, 
and one coin to its right child.

Example 2:
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, 
we move two coins to the root 
[taking two moves]. 
Then, we move one coin from the root 
of the tree to the right child.

題意:
給一顆樹
每個節點有n個硬幣(node->val)
每次只能移動一個硬幣，
要移動幾次讓所有節點都恰有一個硬幣

思路:
1. 假設一個節點有x枚硬幣，要讓這個節點剩一枚硬幣，則要移動 x-1次
2. 不管從左子樹移到右子樹，還是右子樹移到左子樹，都要經過父節點
3. 如果val是0或負數，那就代表需要從別的節點移動硬幣過來
4. 如果val是大於移的正數，代表要把硬幣移出去
5. 不論正數或負數，其絕對值代表硬幣要移動的次數
6. 把問題縮小成 根節點、左節點、右節點 一共三個點節
7. 此根節點需要承擔的 移動次數為 : a+b+c 取絕對值
    a:根節點->val-1
    b:左節點要承擔的的移動次數 
    c:右節點要承擔的的移動次數
8. 從最底層，一層一層統計需要承擔的移動次數
9. 想像葉子節點，它實際需要承擔的移動次數為 node->vale -1, 沒了。
10. 把9計算出來的數字往上一層傳，並層層累計
11. 得解。

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
    int moveTime =0;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moveTime; 
    }
    int dfs(TreeNode* root){
        if(!root)return 0;
        int left =dfs(root->left);
        int right =dfs(root->right);
        int sum = root->val-1+left+right;
        moveTime = moveTime + abs(sum);
        return sum;
    }
};

// Runtime 17 ms Beats 18.22% Memory 13.9 MB Beats 44.9%