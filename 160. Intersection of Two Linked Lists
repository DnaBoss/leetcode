/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
 /*
 題意:找出二個list 第一個交集的node
 思路:為二個list 各建一個 node 把 head 各自指向新的node
 如果有任一個list 到尾了，就把node 指令 另一個 list的head
 這時間就是 O(max(n,m))，記憶體就是O(1)
 很意外的，這題沒有測試[2][3,4,5,6]這種資料, 
 本來有另外為這種情況做判斷的，因為不需要就拿掉了
 */
var getIntersectionNode = function(headA, headB) {
    if (!headA || !headB)
        return null;
    var nodeA = headA;
    var nodeB = headB;
    while (nodeA !== nodeB) {
        nodeA = nodeA === null ? headB : nodeA.next
        nodeB = nodeB === null ? headA : nodeB.next
    }
    return nodeA;
};
