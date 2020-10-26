/**
 * 題目:Given a singly linked list, 
 * group all odd nodes together followed by the even nodes. 
 * Please note here we are talking about the node number and not the value in the nodes.
 * You should try to do it in place. 
 * The program should run in O(1) space complexity and O(nodes) time complexity.
 * 題意 : 給定一單向鏈結串列，把奇數的node 鏈結，把偶數的node 鏈結，奇數鏈結的最後一備node○指向 偶數鏈結的head
 * 思路: 同題意
 * 限制: 空間複雜度 O(1)，時間複雜度O(n)
 * 其實OJ 沒有檢查空間複雜度，O(n)一樣會過
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function (head) {
    if (!head) {
        return head;
    }
    let odd = head;
    let even = head.next
    let evenHead = head.next
    while (even && even.next) {
        odd.next = even.next
        odd = odd.next;
        even.next = odd.next
        even = even.next;
    }
    odd.next = evenHead;
    return head;
};
class ListNode {
    constructor(val, next) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}
// Runtime: 88 ms, faster than 76.01% of JavaScript online submissions for Odd Even Linked List.
// Memory Usage: 41.1 MB, less than 52.40% of JavaScript online submissions for Odd Even Linked List.