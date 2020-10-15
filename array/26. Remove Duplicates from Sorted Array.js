/**
 * 題目:Given a sorted array nums, 
 * remove the duplicates in-place 
 * such that each element appears only once and returns the new length.
 * Do not allocate extra space for another array,
 * you must do this by modifying the input array in-place with O(1) extra memory.
 * 題意:給一個排序過的數字陣列，把重復的數字都去除，只準使用給定的陣列，不能新建陣列
 * 思路:因為是排序過的陣列，所以當前的數字跟下一個數字一樣，就移除當前數字
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let len = nums.length;
    for (let index = 0; index < len - 1; index++) {
        if (nums[index] === undefined || nums[index + 1] === null) {
            return;
        }
        if (nums[index] === nums[index + 1]) {
            console.log(`index:${index},nums[index] :${nums[index]}`)
            nums.splice(index, 1);
            index--;
        }
    }
};

let nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
removeDuplicates(nums)
