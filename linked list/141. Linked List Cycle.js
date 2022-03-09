// 題目:
// Given head, the head of a linked list, 
// determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list 
// that can be reached again by continuously following the next pointer. Internally, 
// pos is used to denote the index of the node that tail's next pointer is connected to. 
// Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.
// Follow up:
// Can you solve it using O(1) (i.e. constant) memory?

// 題意:給定一個鏈結串列，判斷它是否存在循環
// 簡單說，是否有某一個 node 的 next 指向 先前的某個node
// 有的話就是循環，若只是 val 的重覆不算循環

// 思路:用一個陣列存每一個節點
// 每存一個就檢查陣列裡面是否曾經存過這個節點
// 若有，則就是循環的

// 思路2:快慢指針法
// 創建二個變數，從head開始巡訪串列
// 慢的一次往前一節點
// 快的每次往前二個節點
// 若存在循環，則將在某刻會出現 快節點跟慢節點一樣的node
// 這個解法符合 O(1)

class ListNode {
    constructor(val, next) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}



var hasCycle = function (head) {
    let slow = head;
    let fast = head;
    while (slow && fast) {
        if (!slow.next || !fast.next) {
            return false;
        }
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
};
