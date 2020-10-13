
/**
 * 題目:Given two arrays, write a function to compute their intersection.
 * 題意:給定二個陣列，找出交集，交集一次則不再作用
 * 思路O(n^2)的一個解法，二個陣列做 m*n 次檢查，
 * 若一樣就將數字加進一個答案陣列，二個陣列各自splice
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
    let ans = [];
    for (let i = 0; i < nums1.length; i++) {
        for (let j = 0; j < nums2.length; j++) {
            if (nums1[i] === nums2[j]) {
                ans.push(nums1[i]);
                nums1.splice(i, 1);
                nums2.splice(j, 1);
                i--;
                continue;
            }
        }
    }
    return ans;
};
