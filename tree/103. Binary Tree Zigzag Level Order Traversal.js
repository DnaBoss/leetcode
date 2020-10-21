/**
 * 題目:Given a binary tree, return the zigzag level order traversal of its nodes' 
 * values. (ie, from left to right, then right to left for the next level and alternate between).
 * 題意:以z字的形式，按階級歷遍一顆樹，階層1(先左子樹 再 右子樹) 階層2(先右子樹 再 左子樹) 依此類推
 * 思路:102題的變形 用階數%2 來決定要用 push 或 unshift
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var zigzagLevelOrder = function (root) {
    if (!root) {
        return []
    }
    root.levl = 0;
    let levelRecord = {};
    calLevel(root, root.levl, levelRecord);
    let ans = Object.keys(levelRecord).map(level => levelRecord[level]);
    return ans;
};
class TreeNode {
    constructor(val, left, right, levl) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
        this.levl = (levl === undefined ? 0 : levl)
    }
}

/**
*
*
* @param {TreeNode} node
* @param {Number} level
* @param {*} levelRecord
*/
function calLevel(node, level, levelRecord) {
    levelRecord[level] = levelRecord[level] || [];
    if (node) {
        if (level % 2 === 0) {
            levelRecord[level].push(node.val);
        } else {
            levelRecord[level].unshift(node.val);
        }
        if (node.left) {
            calLevel(node.left, level + 1, levelRecord);
        }
        if (node.right) {
            calLevel(node.right, level + 1, levelRecord);
        }
    }
}

let root = new TreeNode(1)
let left = new TreeNode(2)
root.left = left;

let ans = zigzagLevelOrder(root)
console.log('ans = ', ans)

// Runtime: 80 ms, faster than 63.39% of JavaScript online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 40.3 MB, less than 6.49% of JavaScript online submissions for Binary Tree Zigzag Level Order Traversal.