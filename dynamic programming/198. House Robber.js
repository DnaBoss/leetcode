/**
 * 題目:You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, 
 * the only constraint stopping you 
 * from robbing each of them is that adjacent houses have security system 
 * connected and it will automatically contact the police 
 * if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing 
 * the amount of money of each house,
 *  determine the maximum amount of money
 * you can rob tonight without alerting the police.
 * 題意: 給一個非負整數的陣列在不連續選取相鄰的二個數字為前題，找出最大的合
 * 思路:第n個最大的數字，是當前的數字加上第n-2個最大數字和第n-1最大的數字取大
 
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
    let len = nums.length;
    let ans = [];
    ans[0] = nums[0];
    ans[1] = Math.max(nums[0], nums[1]);
    // 設邊界
    if (len == 0) {
        return 0;
    }
    if (len == 1) {
        return nums[0];
    }
    for (let i = 2; i < len; i++) {
        ans[i] = Math.max(ans[i - 2] + nums[i], ans[i - 1])
    }
    return ans[len - 1];
};

let test1 = [2, 1, 1, 2];
let ans = rob(test1);
console.log('ans= ', ans);