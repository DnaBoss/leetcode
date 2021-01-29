/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
    let MAX = Math.ceil(amount / coins[0]);
    let dp = [];
    dp[0] = 0;
    if (amount == 0) {
        return 1;
    }
    if (amount < 0) {
        return 0;
    }

    return coinChange(coins, amount, MAX, dp);

};
function find(coins, amount, min, dp) {
    if (dp[amount - 1] != 0) {
        return dp[amount - 1];
    }
    coins.forEach(coin => {
        let res = find(coins, amount - coin, MAX, dp);
        min = Math.min(MAX, 1 + res);
    })

    if (amount >= 0 && amount < min) {
        min = 1 + amount;
    }
    count[amount - 1] = (min == MAX) ? -1 : min;
    return count[amount - 1];

}


