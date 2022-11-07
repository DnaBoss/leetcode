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
// Given the sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

//       0
//      / \
//    -3   9
//    /   /

// 題意:將排序過的陣列，組成一個二分搜索樹
// 思路: 中間那個數字其實就是 root，以root為中心，左邊的是左子樹、右邊的是右子樹
// 左子樹那堆數字的中心，則是左子樹的root
// 以此類推，指派完每一個節點

/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function (nums) {
    return Convert(nums);
};
/**
 *
 *
 * @param {number[]} nums
 * @param {number} start
 * @param {number} end
 */
function Convert(nums) {
    if (nums.length == 0) {
        return null;
    }
    let midNum = parseInt(nums.length / 2);
    let nodeNum = nums[midNum];
    console.log('nums = ', nums)
    console.log(`midNum:${midNum},nodeNum"${nodeNum}`)
    let node = new TreeNode(nodeNum)
    // if (midNum != 0 && midNum != nums.length - 1) {
    node.left = Convert(nums.slice(0, midNum))
    node.right = Convert(nums.slice(midNum + 1, nums.length +1))
    // }
    return node
}
// 不斷的切出新的arry 放進 convert
// 效能超差
// 於是改寫
// 不切新的array
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function (nums) {
    return Convert(nums, 0, nums.length - 1);
};
/**
 *
 *
 * @param {number[]} nums
 * @param {number} start
 * @param {number} end
 */
function Convert(nums, start, end) {
    if (start > end) {
        return null;
    }
    let midNum = Math.ceil((start + end) / 2);
    let nodeNum = nums[midNum];
    let node = new TreeNode(nodeNum)
    node.left = Convert(nums, start, midNum - 1)
    node.right = Convert(nums, midNum + 1, end)
    return node
}

