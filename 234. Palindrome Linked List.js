題目:Given a singly linked list, determine if it is a palindrome.
題意:判斷一個鏈結串列是不是回文
思路:把所有值存在陣列，頭尾檢查是否相等，記憶中做過字串和陣列的回文判斷題，
所以解起來算簡單，而且測資成績比我想像的好

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
