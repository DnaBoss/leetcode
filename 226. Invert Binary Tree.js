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
