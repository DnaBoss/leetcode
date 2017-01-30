/**
     * @param {number} x
     * @return {number}
     */
//這一題真的讓我翻白眼，在第 12xx個測試的時後WA，程式不過
//測試的數字是 1534236469 測資的提示是 excepted 0
//大概想了一下，我猜是超過 int的上限了，可是我用的語言是javascript 而不是c
//希望leet code 能針對個別語言去設計和修改題目
//因為leet code 不會保留你的解答，所以只好貼來gist
   var reverse = function(number) {
    var _num = number;
    if (_num === 0)
        return 0;
    if (_num < 0)
        _num = 0 - _num;
    var num = parseInt((function(num) {
        var arr = [];
        while (num > 0) {
            var quotient = Math.floor(num / 10);
            arr.push(num % 10);
            num = quotient;
        }
        return arr;
    })(_num).join(''));
    if (num < -2147483648 || num > 2147483647)
        return 0;
    return number > 0 ? num : 0 - num
};
