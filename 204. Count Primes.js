/**
 * @param {number} n
 * @return {number}
 */
 //在n=1500000的時後超過時間了，我猜用c寫的話就過了
var countPrimes = function(n) {
if (n <= 2)
        return 0;
    var prime = [];
    for (var x = 0; x < n; x++) // 初始化
        prime[x] = true;

    prime[0] = false; // 0 和 1 不是質數
    prime[1] = false;

    for (var i = 2; i < n; i++) {
        if (prime[i])
            for (var j = i + i; j < n; j += i)
            prime[j] = false;
    }
    var ans = prime.map((elem, index) => elem === true ? index : false).filter(elem => elem !== false);
    return ans.length;
};

var countPrimes = function(n) {
if (n <= 2)
        return 0;
    var prime = [];
    for (var x = 0; x < n; x++) // 初始化
        prime[x] = true;

    prime[0] = false; // 0 和 1 不是質數
    prime[1] = false;

    // 找下一個未被刪掉的數字
    prime=prime.map()
    for (var i = 2; i < n; i++) {
        if (prime[i])
        // 刪掉質數i的倍數，從兩倍開始。保留原本質數。
            for (var j = i + i; j < n; j += i)
            prime[j] = false;
    }
    var ans = prime.map((elem, index) => elem === true ? index : false).filter(elem => elem !== false);
    return ans.length;
};
