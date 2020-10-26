/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
//  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
   
//  return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]  
// 題意: 要把一個樹中同一個高度的數字都放進一個陣列中
// 再將這些陣列依照高度放在一個陣列中
// 要注意的是，要先加左再加右
// 像範例如果回傳
// [
//   [3],
//   [20,9],
//   [7,15]
// ]  
// 就會測不過

// 思路:
// 用一個物件去存
// level 當 key ，value 是 array
// 依序將同level 放進這個array
// 最後再把key 去掉，依序存進一個array 就好

class TreeNode {
    constructor(val, left, right, level) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
        this.level = (level === undefined ? 0 : level)
    }
}

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function (root) {
    if(!root){
        return []
    }
    root.level = 0;
    let levelRecord = {};
    calLevel(root, root.level, levelRecord);
    let ans = Object.keys(levelRecord).map(level => levelRecord[level]);
    return ans;

};

/**
 *
 *
 * @param {TreeNode} node
 * @param {Number} level
 * @param {*} levelRecord
 */
function calLevel(node, level, levelRecord) {
    levelRecord[level] = levelRecord[level] || [];
    levelRecord[level].push(node.val);
    if (node.left) {
        calLevel(node.left, level + 1, levelRecord);
    }
    if (node.right) {
        calLevel(node.right, level + 1, levelRecord);
    }
  
}

