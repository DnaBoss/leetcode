/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
    let temp = new ListNode(0)
    let current = temp;
    let plus = 0;
    while (l1 && l2) {
        let digits = (l1.val + l2.val + plus) % 10;
        plus = l1.val + l2.val + plus >= 10 ? 1 : 0;
        let node = new ListNode(digits);
        current.next = node;
        current = node;
        l1 = l1.next;
        l2 = l2.next;

    }
    while (l1) {
        let digits = (l1.val + plus) % 10;
        plus = l1.val + plus >= 10 ? 1 : 0;
        let node = new ListNode(digits);
        current.next = node;
        current = node;
        l1 = l1.next;
    }
    while (l2) {
        let digits = (l2.val + plus) % 10;
        plus = l2.val + plus >= 10 ? 1 : 0;
        let node = new ListNode(digits);
        current.next = node;
        current = node;
        l2 = l2.next;
    }
    if (plus === 1) {
        let node = new ListNode(1);
        current.next = node;
    }
    return temp.next;
};

class ListNode {
    constructor(val, next) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
    let temp = new ListNode(0)
    let current = temp;
    let plus = 0;
    while (l1 || l2 || plus) {
        let sum = 0;
        if (l1) {
            sum = sum + l1.val;
            l1 = l1.next;
        }
        if (l2) {
            sum = sum + l2.val;
            l2 = l2.next;
        }
        let digits = (sum + plus) % 10;
        plus = sum + plus >= 10 ? 1 : 0;
        let node = new ListNode(digits);
        current.next = node;
        current = node;
    }
    return temp.next;
};