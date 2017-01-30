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
var swapPairs = function(head) {
    var _root = new ListNode(-1);

    _root.next = head;
    var prev = _root;
    var cur = head;

    while (prev.next !== null && prev.next.next !== null)
        prev = swap(prev, prev.next, prev.next.next);
    return _root.next;

    function swap(prev, cur, next) {
        var rem = next.next;
        prev.next = cur.next;
        cur.next.next = cur;
        cur.next = rem;
        return cur;
    }
};
