
/**
 * 題目:Given an array nums, 
 * write a function to move all 0's to the end 
 * of it while maintaining the relative order of the non-zero elements.
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 注意:不能新建陣列、最小化對數字的總操作
 * 題意:給一個數字陣列，把0全移到陣列後面
 * 思路:沒有什麼思路 只要知道 javascript 有 splice 這個方法就好了
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
    let countZero = 0;
    let len = nums.length;
    for (let i = 0; i < len - 1; i++) {
        if (nums[i] === 0) {
            nums.splice(i, 1);
            countZero = countZero + 1;
            i--;
        }
    }
    while (countZero) {
        nums.push(0);
        countZero = countZero - 1;
    }
};
