/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 * 
 * 
 * Given two binary trees, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 * 題意:給定二個二元樹，檢查二顆查是否一樣(一樣的值以及一樣的結構)
 * 
 * 解題思路:檢查節點是否都有值或都沒值，檢查值、遞迴檢查左節點及右節點
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */



var isSameTree = function(p, q) {
 
    if ((p && !q) || (!p && q)) {
        return false;
    }

    return !p && !q||(p.val === q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right))
};