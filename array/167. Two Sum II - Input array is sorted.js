/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
/**
題目:給定一個 number[] , 找出index1跟index2
使得number[index1]+number[index2] = target
且index2>index1
 */
//不會過，因為超過time limit
var twoSum = function (numbers, target) {
    var resA = 0;
    var resB = 0;
    numbers.find((numA, index1) => {
        numbers.find((numB, index2) => {
            if (numA + numB === target && index2 > index1) {
                resA = index1 + 1;
                resB = index2 + 1;
            }
        })
    })
    return [resA, resB];
};
//縮小迴圈範圍，過了，但測資表現極差 O(n^2)
var twoSum = function (numbers, target) {
    var resA = 0;
    var resB = 0;
    var len = numbers.length;
    for (var numA = 0; numA < len; numA++) {
        for (var numB = numA + 1; numB < len; numB++) {
            if (numbers[numA] + numbers[numB] === target) {
                resA = numA + 1;
                resB = numB + 1;
                break;
            }
        }
    }
    return [resA, resB];
};
// O(n)
var twoSum = function (nums, target) {
    let obj = {};
    let len = nums.length;
    let pos = 0;
    while (pos < len) {
        let num = nums[pos];
        if (obj[target - num] >= 0) {
            return [obj[target - num], pos]
        }
        obj[num] = pos;
        pos++;
    }
}

// Runtime: 60 ms, faster than 99.94% of JavaScript online submissions for Two Sum.
// Memory Usage: 40.6 MB, less than 12.67% of JavaScript online submissions for Two Sum.