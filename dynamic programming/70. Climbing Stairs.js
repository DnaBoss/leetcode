/**
 * 題目:You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
 * 題意:你正在爬一坐有n階的階梯，每次你可以選爬一階或爬二階
 * 請問爬一坐n階的階梯一共有多少不同的爬法
 * 思路:首先就是要先發現前面幾個階梯的爬法，很像是一個費伯那希數列
 * 雖然無法證明，但猜想它應該就會是費伯那希數列，如果是的話就好解了
 * (意識不到第n個數等於第n-1個數+第n-2個數就不用玩了)
 * 很多基礎教科書都有教過，試了一下，果然是，一般教科書都用遞迴，
 * 但大家都知道遞迴效率比較差，所以這裡就先建立首二筆資料，之後的就用for 算出來
 * 就for 迴圈跑n次，每次執行一個加法運算
 * 
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    let fb = [];
    fb[0] = 1;
    fb[1] = 1
    for (let index = 2; index <= n; index++) {
        fb[index] = fb[index - 1] + fb[index - 2];
    }
    return fb[n];
};

// Runtime: 68 ms, faster than 93.29% of JavaScript online submissions for Climbing Stairs.
// Memory Usage: 38.6 MB, less than 14.65% of JavaScript online submissions for Climbing Stairs.