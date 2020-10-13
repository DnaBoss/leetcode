/**
 * Definition for singly-linked list.
 * function ListNode(val) { 
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
/**
 思路，建一個 pre-前一個
 建一個temp 存 head的下一個
 head 指向前一個
 把 head assign 給 pre
 把 temp assign head
  */
var reverseList = function(head) {
    var pre = null;
    // if (!head || !head.next) return head;
    while (head !== null) {
        var temp = head.next;
        head.next = pre;
        pre = head;
        head = temp;
    }
    return pre;
};
