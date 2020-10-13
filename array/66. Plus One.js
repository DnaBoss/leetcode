/**
題目: Given a non-empty array of digits representing a non-negative integer, 
 increment one to the integer.
The digits are stored such that 
the most significant digit is at the head of the list,
and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero,
 except the number 0 itself
 題意: 給一個數字陣列，將此陣列組合而成的數字+1，以陣列的形式回傳
 思路: 以前寫過大數加法，稍微改一下就直接拿來用，
 用一個新陣列儲存每次相加的結果，用一個變數記錄進位
*/

/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
    let newArr = []
    let oneArr = [1];
    let plus = 0;
    while (digits.length || plus) {
        let add = ~~digits.pop() + ~~oneArr.pop() + plus;
        plus = add >= 10 ? 1 : 0;
        let inside = (add % 10)
        newArr.push(inside);
    }
    return newArr;
};