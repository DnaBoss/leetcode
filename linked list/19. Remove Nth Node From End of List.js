/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
 題目：Given the head of a linked list, remove the nth node from the end of the list and return its head.
 題意：單向鏈結串列，給一個ｎ，除出從最後一個算起第ｎ個ｎｏｄｅ
 思路，用一個容器裝每一個ｎｏｄｅ，並記用容器記錄這是第幾備ｎｏｄｅ
若ｎ為ｃｕｒｒｅｎｔ　ｎｏｄｅ，ｎ－１則為ｐｒｅ　ｎｏｄｅ，ｎ＋１為ｎｅｘｔ　ｎｏｄｅ
把ｐｒｅ　ｎｏｄｅ　的ｎｅｘｔ　指像　ｎｅｘｔ　ｎｏｄｅ，結束
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let current = new ListNode(head.val, head.next);
    let listLen = 0;
    let nodeList = {}
    while (current) {
        nodeList[listLen] = current;
        listLen = listLen + 1;
        current = current.next;
    }
    let next = nodeList[listLen - n + 1] || null;
    head = nodeList[0];
    if (nodeList[listLen - n - 1]) {
        nodeList[listLen - n - 1].next = next;
    }
    if (listLen - n == 0) {
        head = head.next;
    }
    return head;
};
