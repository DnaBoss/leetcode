/**
 * 題目:You are a product manager and currently leading a team to develop a new product.
 *  Unfortunately, the latest version of your product fails the quality check. 
 * Since each version is developed based on the previous version, 
 * all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] 
 * and you want to find out the first bad one, 
 * which causes all the following ones to be bad.
 * You are given an API bool isBadVersion(version)
 * which returns whether version is bad. 
 * Implement a function to find the first bad version. 
 * You should minimize the number of calls to the AP
 * 題意:題目會給一個fucntion isBadVersion 用來測試版本是否正常，以及一個數字n
 * 在1~n 之間有某個版本壞了，設為x版，x版之後的每一個版本也都會是壞的
 * 找出x
 * 思路:2分法，基本上全部的code 都沒問題，但測資卡了超級久
 * 因為我回傳設成 version ，
 * 而且我還一直覺得沒問題，最後改成 return lowerBound就過了
 * 腦子卡住真可怕
 * 
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function (isBadVersion) {

    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function (n) {
        let lowerBound = 1;
        let upBound = n;
        let version = 0;
        while (lowerBound < upBound) {
            version = parseInt((upBound - lowerBound) / 2) + lowerBound;
            check = isBadVersion(version);
            if (check) {
                // 往下找
                upBound = version;
            } else {
                // 往上找
                lowerBound = version + 1;
            }
        }
        return lowerBound;
    };
};

// Runtime: 76 ms, faster than 59.10% of JavaScript online submissions for First Bad Version.
// Memory Usage: 38.4 MB, less than 15.51% of JavaScript online submissions for First Bad Version.