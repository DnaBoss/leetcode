/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
題意，反轉一顆二元樹
思路 : 建一個temp 的 node 來記錄左或右子節點，swap，每一個左子、右子節點照做，回傳root，收工
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function (root) {
    if (!root) {
        return root
    }
    if (root.right) {
        let tempNode = new TreeNode(root.right.val, root.right.left, root.right.right);
        root.right = root.left;
        root.left = tempNode
    } else if(root.left){
        let tempNode = new TreeNode(root.left.val, root.left.left, root.left.right);
        root.left = root.right;
        root.right = tempNode
    }

    invertTree(root.right);
    invertTree(root.left);
    return root
};

class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}
