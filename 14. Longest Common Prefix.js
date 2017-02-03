/**
 * @param {string[]} strs
 * @return {string}
 */
/*
解題思路
以第一個字串為標準元素
對陣列內每一個字串，檢查相同的indexof 
看有幾個相同的字元，回傳到一個新陣列
找出最小的的數字，對第一個字串取substring > 回傳 > 結案。
問題:雖說難度easy，但在處理邊界值的時後還是花了不少時間，
覺得他的規則沒有非常詳細，必需讓使用者自己試規則 
*/
var longestCommonPrefix = function(strs) {
    var len = strs.length;
    var first = strs[0];;
    if (len === 0) return "";
    if (len === 1) return first;
    var flen = first.length;
    var str_arr = strs.map((str, index) => {
        var temp = 0;
        for (var i = 0; i <flen ; i++) {
            if (first[i] === str[i]) {
                temp = temp + 1;
            } else break;
        }
        return temp;
    });
    var min = Math.min(...str_arr);
    return first.substring(0, min);
};
