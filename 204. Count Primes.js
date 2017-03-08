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
//★★★★★★★★★★★★★★★★★★換個解法★★★★★★★★★★★★★★★★★★
//如果 C 不是質數 => C必能寫成 C=p*q的形式
//假設p<=q  => p^2 小於等於 C,then we can say p less then sqrt(C)
//建一個 小於 sqrt(p) 的質數表，跑一個迴圈，
//把3~C之間的數都去對除質數表裡的數，能整除就不是質數  
function countPrimes(n) {
    if (n <= 2) return 0;
    var prime = [];
    for (var x = 0; x < n; x++) {
        prime[x] = true;
    }
    //先把 2 算進來了
    var count = 1;
    var sqrt_n = Math.sqrt(n);
    //核心思考:如果一個數n 不是任何一個小於sqrt(n)的質數的倍數，那它就是質數
    //check odd number only，cuz even number 100% not a  prime number
    for (var i = 3; i < n; i += 2) {
    	//
        if (prime[i]) {
            count++;
            if (i > sqrt_n) continue;
            //質數的倍數一定不是質數....
            for (var j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    return count;
}

//這題滿妙的，javascript 大勝 python、swift、ruby的解題者
//甚至還贏過某些 c/c++的解題者，但卻輸了了c#(一般來說表現都會比c#好)
//覺得演算法和語言支持真的有差 

