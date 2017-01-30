
/*
建一個新的list
建一個比較node val的function<<<一開始想用遞迴
如果二個list 有任一個是 null 則把另一個list 剩下的node 接上， 並回傳
如果用遞迴 ，在下列這組測資
[-9, -7, -3, -3, -1, 2, 3]
[-7, -7, -6, -6, -5, -3, 2, 4]
會出現Runtime erroe
我想知道詳細的錯誤，所以移回本機做測試，找出的錯誤是
RangeError: Maximum call stack size exceeded
平常開發其實幾乎沒看過這種錯，
本來以為是遞迴呼叫太多次，google了一下有人說是因為循環遞迴了，
應該是那裡沒寫好，因為改成while就過了，舊的code洗掉了，也來不及查找問題了. 
覺得自已對list的問題不太拿手。
*/
var mergeTwoLists = function(l1, l2) {
    var root = new ListNode();
    var current = root;
    while (l1 !== null && l2 !== null) {
        if (l1.val < l2.val) {
            current.next = l1;
            current = current.next;
            l1 = l1.next;
        }
        else {
            current.next = l2;
            current = current.next;
            l2 = l2.next;
        }
        
    }
    if (l1 === null)
        current.next = l2;
    if (l2 === null)
        current.next = l1;
    return root.next;
};
