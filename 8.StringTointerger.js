/**
 * @param {string} str
 * @return {number}
 */
//有點簡單，雖然這本來就是Easy 等級的題目，只是我看AC 13.8%,本來以為可能會難一滴的滴，結果沒有
var myAtoi = function(str) {
    var num = parseInt(str);
    if (num > 2147483647)
        return 2147483647;
    if (num < -2147483648)
        return -2147483648;
    return num.toString() === 'NaN' ? 0 : parseInt(str);
};
