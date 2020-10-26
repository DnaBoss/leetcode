/**
 * 題目:Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * 題意:給一個根節點，用中序歷遍
 * 思路:用一個array 照定中序定義存起來，然後回傳，沒有什麼思路可言
 * * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 * 
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
    let store = [];
    if (root) {
        inOrder(root, store);
    }
    return store
};
/**
 *
 *
 * @param {TreeNode} node
 * @param {number[]} store
 */
function inOrder(node, store) {
    if (node.left) {
        inOrder(node.left, store);
    }
    store.push(node.val);
    if (node.right) {
        inOrder(node.right, store);
    }
}
class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}

// Runtime: 68 ms, faster than 95.94% of JavaScript online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 38.4 MB, less than 30.84% of JavaScript online submissions for Binary Tree Inorder Traversal.