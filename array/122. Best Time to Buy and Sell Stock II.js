/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let len = prices.length;
    if (!len) {
        return 0;
    }
    let holdStockPrices = 0;
    let profit = 0;
    for (let day = 0; day < len; day++) {
        if (day === 0) {
            holdStockPrices = prices[day];
            console.log('holdStockPrices =', holdStockPrices)
        }
        if (prices[day] < holdStockPrices) {
            holdStockPrices = holdStockPrices = prices[day];
        }
        console.log(`holdStockPrices:${holdStockPrices},prices[day] :${prices[day]}`)
        if (prices[day] > holdStockPrices) {
            profit = profit + (prices[day] - holdStockPrices);
            holdStockPrices = prices[day];
        }

    }
    return profit;
};

let stocksPrices = [2, 1, 2, 0, 1];
let ans = maxProfit(stocksPrices)
console.log(ans)

// Runtime: 76 ms, faster than 87.39% of JavaScript online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 39.2 MB, less than 9.80% of JavaScript online submissions for Best Time to Buy and Sell Stock II.