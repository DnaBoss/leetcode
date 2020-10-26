// 題目:Reverse a singly linked list.
// 題意:反轉一個單向的鏈結串列
// 思路:用三個變數記錄node，
// prev 記錄前一個
// current 記錄當前的
// next 記錄下一個
// 不斷的把後一個的next 指向前一個node

// 程式碼:
var reverseList = function (head) {
    let prev = null;
    let current = head;
    while (current) {
        let next = current.next;
        current.next = prev;
        prev = current
        current = next;
    }
    return current;
};
