/**
 * 題目:Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction
 * (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 * 題意:給定一個數字陣列，假設為某支股票的連續價格，在某n點買進m點賣出會有最大利潤，求最大利潤
 * (注意無法用過去的價格賣出，意即不能用 prices[i+1]的價格買進，用 prices[i]的價格賣出)
 * 思路1,二個for，每個數字都兩兩相減，記錄最大的數字 O(n^2)
 * 思路2,一個for，但記錄最小的數字，進而求出最大利潤 O(n)
 * 
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let len = prices.length;
    let profit = 0;
    for (let i = 0; i < len - 1; i++) {
        for (let j = i + 1; j < len; j++) {
            let tempProfit = prices[j] - prices[i];
            if (tempProfit > profit) {
                profit = tempProfit;
            }
        }
    }
    return profit <= 0 ? 0 : profit;
};
// Runtime: 200 ms, faster than 22.03% of JavaScript online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 47.5 MB, less than 8.85% of JavaScript online submissions for Best Time to Buy and Sell Stock.

var maxProfit = function (prices) {
    let len = prices.length;
    let min = prices[0];
    let profit = 0;
    for (let i = 0; i < len; i++) {
        if (prices[i] < min) {
            min = prices[i];
        }
        let tempProfit = prices[i] - min
        if (tempProfit > profit) {
            profit = tempProfit
        }
    }
    return profit ;
};
// Runtime: 72 ms, faster than 96.54% of JavaScript online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 39.2 MB, less than 8.85% of JavaScript online submissions for Best Time to Buy and Sell Stock.

let test1 = [7, 1, 5, 3, 6, 4];
let test2 = [1, 2]
let ans = maxProfit(test1);
console.log('ans = ', ans)

