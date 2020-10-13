/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
 題意: 檢查一個樹是否是相似的(對稱的)
 思路 :
 第一次先比較 左子節點及右子節點
 之後每一次都要比較其左子節點的左子節點是否等於右子節點的右子節點，
以及左子節點的右子節點要等於右子節點的左子點點
一層一層檢查下去，都一樣就是  Symmetric Tree
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function (root) {
     return !root ? true : isSymmetricTest(root.left, root.right);
};
/**
 *
 *
 * @param {TreeNode} nodeA
 * @param {TreeNode} nodeB
 * @returns
 */
function isSymmetricTest(nodeA, nodeB) {
    if (!nodeA && !nodeB) {
        return true;
    }
    return nodeA && nodeB && nodeA.val == nodeB.val ?
        isSymmetricTest(nodeA.left, nodeB.right) && isSymmetricTest(nodeA.right, nodeB.left):
        false;
}
