/**
 * 題目:Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 題意:給二個排序過的數字陣列，將這二個陣列合併成一個排序過的陣列
 * 思路:將第二個陣列加進第一個陣列，然後排序，結束
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
    nums1.splice(m, nums1.length - m);
    while (nums2.length > 0) {
        let num = nums2.shift();
        nums1.push(num);
    }
    nums1.sort((a, b) => a - b);
};
let nums1 = [1, 2, 3, 0, 0, 0];
let nums2 = [2, 5, 6];
merge(nums1, 3, nums2, 3);