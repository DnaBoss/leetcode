/*
Given the head of a linked list and an integer val,
remove all the nodes of the linked list that has Node.val == val, 
and return the new head.

題意:刪除鏈結串列上所有指定值的節點
思路:建虛擬節點為head，用while 歷遍所有節點
istNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        while(cur->next!=nullptr){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        return dummyNode->next;
    }
};