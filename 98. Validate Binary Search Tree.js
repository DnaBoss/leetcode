/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
題意:給定一個根節點，判斷是否為二元樹

一開始的思路是 每一個節點的左子節點都小於它，右子節點都大於它
然後測到一個 右子樹放一個小於root的val的測資就過fail了
var isValidBST = function(root) {
        if (root == null) {
        return true;
    }
    if (root.left && root.left.val >= root.val) {
        return false;
    }
 
    if (root.right && root.right.val != 0 && root.right.val <= root.val) {
        return false;
    }
    // 有左子也有右子
    if (root.right && root.left) {
        return isValidBST(root.right) && isValidBST(root.left)
    }
    // 沒有子節點
    if (!root.right && !root.left) {
        return true;
    }
    // 只有右子節點
    if (root.right && !root.left) {
        return isValidBST(root.right);
    }
    // 只有左子節點
    if (!root.right && root.left) {
        return isValidBST(root.right);
    }
};

思路2:用中序把每一個點的值都存在array，只要每一個 array[index] 都小於 array[index+1] 就是二元樹了

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function (root) {
    let arr = [];
    let ans = true;
    inOrder(root, arr);
    for (let index = 0; index < arr.length - 1; index++) {
        let check = arr[index] < arr[index + 1];
        if (!check) {
            ans = false;
        }

    }
    function inOrder(node, arr) {
        if (node) {
            inOrder(node.left, arr);
            arr.push(node.val);
            inOrder(node.right, arr);
        }
    }
    return ans;
}
