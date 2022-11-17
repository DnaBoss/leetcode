/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
題意:找出一顆 BST 的眾數
用 VECTOR 返還(可以有多個眾數)

思路:
解法1:中序遍歷，收集成到容器內
迭代迴圈，計算哪個出現最多次，加進 VECTOR內

解法2:用DFS跟全域變數記錄前一個節點
如果當前節點跟前一個節點是相同數字，則計次+1
如果計次等於最大計次，則加進容器內
如果計次大於最大計次，清空容器，把數字加進容器、更新最大計次的值
*/