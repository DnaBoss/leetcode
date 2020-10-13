/**
題目:Given a non-empty array of integers nums, 
every element appears twice except for one. Find that single one.
Follow up: Could you implement a solution 
with a linear runtime complexity and without using extra memory?
題意 :給一個非空的整數陣列，每個數次都會出現二次，唯獨一個數字不會，請找出沒有重覆出現的數字
思路:用一個容器記得每個數字出現的次數，再找出只出現一次的數字回傳
*/
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
    let numObj = {};
    nums.forEach(num => numObj[num] = ~~numObj[num] + 1);
    return Object.keys(numObj).find(key => numObj[key] === 1);
};
// 網路解 有人用 xor，理解後測資通過
var singleNumber = function (nums) {
    let ans = 0;
    nums.forEach(num => ans ^= num);
    return ans;
};
