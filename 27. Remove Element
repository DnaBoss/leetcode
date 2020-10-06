Given an array nums and a value val, 
remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. 
It doesn't matter what you leave beyond the new length.
題意: 把一個 Array<Number> 中指定的數字 移除，不能使用新的Array
要求時間複雜度 O(n)，空間複雜度 O(1)
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    for (let index = 0; index < nums.length; index++) {
        if (nums[index] == val) {
            nums.splice(index, 1);
            index--
        }
    }
    return nums.length;
};

簡單的改寫，提升效能
從 faster then 43% 提升到 faster then 70%
var removeElement = function(nums, val) {
    let index = 0
    while ( index < nums.length) {
        nums[index] == val ?nums.splice(index, 1)&&index--:index++
    }
    return nums.length;
};
