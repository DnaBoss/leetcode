題意:給定一個陣列，要你排出它所能組成的最大數字
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
把這個數列裡面的元素按照大小排好，組合成字串 return 回去。
但是，想一想30>3 可是 330>303，所以如果a+b>b+a，我們應該要認為a>b，
按照這個規則去排序，結束。
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    var numbers = nums.sort((a, b) => ('' + b + a) - ('' + a + b)).join('')
    return numbers[0] === '0' ? '0' : numbers;
};
