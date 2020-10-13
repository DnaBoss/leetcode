/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}
/**
題意: 對一個樹做 preorder 及 inorder 的巡訪，各產生一個數字陣列
以此二個陣列還原這顆樹

思路:preorder 的第一個數字是 root
inorder 的 root陣列中，左邊的數字構成 root的左子樹，右邊的數字構成右子樹
用 preorder inorder 和一些邊界值做輔助 迭代出原本的樹

 *
 *
 * @param {Array<Number>} preorder
 * @param {Array<Number>} inorder
 * @param {Number} preLeft
 * @param {Number} preRight
 * @param {Number} inLeft
 * @param {Number} inRight
 */
function buildTree(preorder, inorder) {
    return builder(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);

}

function builder(preorder, inorder, preLeft, preRight, inLeft, inRight) {
    // 邊界判定
    if (preLeft > preRight || inLeft > inRight) {
        return null;
    }
    let rootVal = preorder[preLeft];
    let node = new TreeNode(rootVal);
    // 找出根值在中序中的位置 i 
    for (let i = inLeft; i <= inRight; i++) {

        if (inorder[i] == rootVal) {
            // 找左子節點
            node.left = builder(preorder, inorder, preLeft + 1, preLeft + (i - inLeft), inLeft, i - 1);
            // 找右子節點
            node.right = builder(preorder, inorder, preLeft + (i - inLeft) + 1, preRight, i + 1, inRight);
            break;
        }
    }
    return node;
}
