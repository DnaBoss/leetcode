class ListNode {
    constructor(val, next) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let current = head;
    let arr = [];
    while (current) {
        arr.push(current.val);
        current = current.next;
    }
    let isPal = true;
    let len = arr.length-1;
    for (let head = 0, tail = len; head < tail; head++, tail--) {
        if (arr[head] !== arr[tail]) {
            isPal = false;
        }
    }
    return isPal
};
