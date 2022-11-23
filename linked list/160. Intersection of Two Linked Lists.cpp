
/*
題目:https://leetcode.com/problems/intersection-of-two-linked-lists/description/
題意: 給二個鏈結串列，他們在某一個節點之後會開始都是一樣的鏈結，找出那個起始節點
思路:
計算二個串列的長度，固定一邊為長邊，
調整長邊的起點到跟短邊一樣，一起往下循環，直到找到同個節點
找不到就返回NULL
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * dummyA = headA;
        ListNode * dummyB = headB;
        int aSize = 0;
        int bSize = 0;
        // 各自計算二個鏈結的長度
        while(dummyA){
            dummyA = dummyA->next;
            aSize++;
        }
        while(dummyB){
            dummyB = dummyB->next;
            bSize++;
        }
        // 這裡其實就是要把B故意調整成比較短的鍵結，然後去調整A的查看位置，反過來做也可以
        if(aSize > bSize){
            dummyA = headA;
            dummyB = headB;
        }else{
            dummyA = headB;
            dummyB = headA;
        }
        int diff = abs(aSize - bSize);
        while(diff--){
            dummyA = dummyA->next;
        }
        // 只要有一邊走到空了，卻還沒發現交點，程式就結束了
        while(dummyA || dummyB){
            if(dummyA == dummyB){
                return dummyA;
            }
            dummyA = dummyA->next;
            dummyB = dummyB->next;
        }
        return NULL;
    }
};

// Runtime 58 ms Beats 83.82% Memory 14.5 MB Beats 74.30%