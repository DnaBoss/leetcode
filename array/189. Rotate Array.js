/**
 * 題目:Given an array, rotate the array to the right by k steps, where k is non-negative.
 * 題意:執行k次，將陣列的最未移到最首的操作
 * 思路: 沒有什麼思路，會用pop 跟 unshift 就好
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    while (k) {
        let num = nums.pop();
        nums.unshift(num)
        k--
    }
    return nums;
};

// Runtime: 116 ms, faster than 35.81% of JavaScript online submissions for Rotate Array.
// Memory Usage: 39.6 MB, less than 5.32% of JavaScript online submissions for Rotate Array.

let nums = [1, 2, 3, 4, 5, 6, 7];
let ans = rotate(nums, 3)
console.log('ans= ', ans)