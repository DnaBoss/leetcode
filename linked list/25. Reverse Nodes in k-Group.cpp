/*
題目:https://leetcode.com/problems/reverse-nodes-in-k-group/
題意:每k個節點為一組，做翻轉，不滿k個節點則不翻轉
思路:找到要被翻轉的頭 and 尾+1節點，透過翻轉函式去翻轉，然後 recursive 去執行
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for(int i = 0; i < k; i++){
            if(!node)return head;
            node = node->next;
        }
        auto res = reverse(head,node);
        head->next = reverseKGroup(node,k);
        return res;
    }

    ListNode* reverse(ListNode* start,ListNode* end){
        ListNode* pre = end;
        while(start != end){
            auto next = start->next;
            start->next = pre;
            pre = start;
            start = next;
        }
        return pre;
    }

};

