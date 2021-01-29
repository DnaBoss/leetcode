/**
 * 題目:
Given a string containing digits from 2-9 
inclusive, return all possible letter combinations 
that the number could represent. 
Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons)
is given below. 
Note that 1 does not map to any letters.
題意:以前的電話按鍵上會有 數字鍵，
旁邊會包含者3~4個英文字，
通常都有固定對應，
2 對應 a,b,c 
3 對應 d,e,f
輸入 一串數字
輸出 所有可能組成的英文對應

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

思路: 先建一張mapping 表
把它組成一個二維陣列，digs
把第一個陣列當做基礎陣列
呼叫副程式
副程式:

shift 出一個一維陣列
將這二個陣列組合成新的基礎陣列
遞迴副程式

 * @param {string} digits
 * @return {string[]}
 */
const mapping = { 1: "", 2: "abc", 3: "def", 4: "ghi", 5: "jkl", 6: "mno", 7: "pqrs", 8: "tuv", 9: "wxyz" };
var letterCombinations = function (digits) {
    let digs = digits.split('').map(num => mapping[num].split(''));
    if (digs.length < 1) {
        return digs;
    }
    let ans = digs.shift();
    return sub(digs, ans);
};
function sub(digs, ans) {
    if (digs.length < 1) {
        return ans;
    }
    let dig = digs.shift();
    let store = [];
    for (let i = 0; i < ans.length; i++) {
        for (let j = 0; j < dig.length; j++) {
            let str = ans[i] + dig[j];
            store.push(str)
        }
    }
    return sub(digs, store);
}
// test input '' ,'2','23'

// Submission Detail
// 25 / 25 test cases passed.
// Status: Accepted
// Runtime: 72 ms
// Memory Usage: 38.4 MB

// Your runtime beats 90.52 % of javascript submissions