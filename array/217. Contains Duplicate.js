/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
    let record = {}
    return nums.some(num => {
        if (record[num]) {
            return true;
        }
        record[num] = ~~record[num] + 1;
    }
    )
};