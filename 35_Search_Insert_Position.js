/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    if (nums.includes(target))
        return nums.indexOf(target);
    if (target < nums[0])
        return 0;
    if (target > nums[nums.length - 1])
        return nums.length;
    var temp = [];
    for (var i = 0; i < nums.length; i++) {
        if (target > nums[i] && target < nums[i + 1]) {
            temp.push(nums[i])
            temp.push(target)
        } else {
            temp.push(nums[i])
        }
    }
    return temp.indexOf(target);
};

