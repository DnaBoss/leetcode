/*
Given the head of a singly linked list 
where elements are sorted in ascending order, 
convert it to a height-balanced
binary search tree.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], 
which represents the shown height balanced BST.

題意:把一個linked list 轉化成一顆binary search tree
思路:
其實這題有幾個解法
1.去計算 linked list 用中序 去建樹
2.用 容器 去存 linked list的val，用中序去把樹的節點一個一個new出來
3.用快慢指針去找到中間節點，當root and 返還root，然後recursion 二段，
一段從heap到中間節點，一段從中間節點到最後一個節點
總之就是要想辨法找到中間節點，用中序去建樹
所以不論如何，大致三脫離不了這三種思路，我選擇3，最優雅簡潔

用2可能會最快，因為只要遍歷一次鏈結串列，之後都能直接拿到中間節點

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head,nullptr);
    }
    TreeNode* buildTree(ListNode* head,ListNode* tail) {
        if(head==tail)return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail && fast-> next != tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildTree(head,slow);
        root->right = buildTree(slow->next,tail);
        return root;
    }
};

// Runtime 51 ms Beats 52.48% Memory 28.3 MB Beats 65.55%