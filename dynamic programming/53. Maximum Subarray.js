/**
 * 題目:Given an integer array nums, 
 * find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * Follow up: If you have figured out the O(n) solution, 
 * try coding another solution using the divide and conquer approach, which is more subtle.
 * 題意:找出一個陣列中最大的連續子陣列 之和
 * 思路先看最大的數是不是正數，不是的話直接回傳最大的數
 * 建立二個變數，一個是存方當前正在連續計算的子陣列之和，
 * 一個存在目前為止記錄最大的子陣列之和
 * 把第一個數假設為最大子陣列之和
 * 先跟0比，看有沒有比0大，再跟當前最大子陣列之和比，
 * 看有沒有比當前最大子陣列大，
 * 有的話就取代成為當前最大子陣列，
 * 沒有的話就繼續往數列的下一個數加
 * 
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    let biggestNum = findBiggestNumber(nums);
    if (biggestNum <= 0) {
        return biggestNum;
    }
    let len = nums.length;
    let max = 0;
    let tempMaxSum = nums[0];
    for (let i = 0; i < len; i++) {
        max = Math.max(0, max + nums[i]);
        tempMaxSum = Math.max(max, tempMaxSum);
        // console.log(`i:${i},nums[i]:${nums[i]},max:${max},tempMaxSum:${tempMaxSum}`);
    }
    return tempMaxSum;
};
function findBiggestNumber(nums) {
    let len = nums.length;
    let biggest = nums[0];
    for (let i = 1; i < len; i++) {
        biggest = Math.max(nums[i], biggest);
    }
    return biggest;
}
// Runtime: 96 ms, faster than 27.78% of JavaScript online submissions for Maximum Subarray.
// Memory Usage: 39.4 MB, less than 7.13% of JavaScript online submissions for Maximum Subarray.
let test1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
let test2 = [-12345];
let test3 = [-1, -2];
let test4 = [-2, 1];
let ans = maxSubArray(test4);
console.log('ans = ', ans);