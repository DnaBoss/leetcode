/**
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
    traval(root, store);
    store.sort((a, b) => a - b);
    return store[k - 1]
};
function traval(node, store) {
    store.push(node.val);
    if (node.left) {
        traval(node.left, store);
    }
    if (node.right) {
        traval(node.right, store);
    }
}