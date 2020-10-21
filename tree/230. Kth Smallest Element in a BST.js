/**
 * 題目:Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * 題意:找出第k小的的數字
 * 思路，歷遍所有節點，把所有數字存在陣列，排序，回傳 陣列[k-1]即可
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function (root, k) {
    if (!root) {
        return;
    }
    let store = []
    travel(root, store);
    store.sort((a, b) => a - b);
    return store[k - 1]
};
function travel(node, store) {
    store.push(node.val);
    if (node.left) {
        travel(node.left, store);
    }
    if (node.right) {
        travel(node.right, store);
    }
}