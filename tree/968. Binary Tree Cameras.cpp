/*
You are given the root of a binary tree.
We install cameras on the tree nodes 
where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough 
to monitor all nodes if placed as shown.

Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras 
are needed to monitor all nodes of the tree. 
The above image shows one of 
the valid configurations 
of camera placement.

題意:給一顆二元樹，要挑其中的節點安裝鏡頭
一個鏡頭可以覆蓋到 自身節點、父節點、左子節點、右子節點
最少要用幾個鏡節，覆蓋所有節點

思路:
當進行後序走訪時(很重要)
每個節點會有三種狀態，
0.未被覆蓋 
1.設有鏡頭
2.已被覆蓋
這三種狀態是為了告知父節點自身的情況，讓父節點去做處理

def:空節點是被覆蓋的(否則就得在每個葉節點裝鏡頭)

a. 後序走訪 為每個節點設定狀態

b. 什麼情況這個節點要設鏡頭?(設為狀態 1)
如果 左、右 子節點只要有一個節點未被覆蓋，
則此時身為父節點，必需裝鏡頭, 並將此節點設為 1

c. 什麼情況這個節點會被覆蓋?(設為狀態 2)
左、右 子節點，其中一個有裝鏡頭(狀態 1)
此時父節點就會被覆蓋到，可以設此節點為 2

d. 什麼情況這個節點會未被覆蓋(設為狀態 0)
左、右 子節點 都被覆蓋的情況，
此時父節點不需要設置鏡頭，同時也沒有鏡頭覆蓋到父節點
故設自身狀態為 0

e. 最後回到根節點，若dfs判斷節點狀態，
根節點為0，則設置鏡頭就好，不用再設狀態了
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
    int cameraNum = 0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==0)cameraNum=cameraNum+1;
        return cameraNum;
    }
    int dfs(TreeNode* node){
        // 0 uncover,1 set camera, 2 covered
        if(!node)return 2;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if(left==0||right==0){
            cameraNum = cameraNum+1;
            return 1;
        }
        if(left==2&&right==2)return 0;
        if(left==1||right==1)return 2;
        return -1;
    }
};

// Runtime 12 ms Beats 86.96% Memory 21.2 MB Beats 87.4%