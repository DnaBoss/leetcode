/**
 * @param {number} n
 * @return {boolean}
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
題意是說，給定一個數字n，將其拆成多個單一的整數 即 0~9
求得每一個單一的數字的平方後，相加，將結果再做重樣的事
問，n最後是否可以求得為 1 的和 
*/

//解題思路
//n 等於 零就不用玩了，建立一個容器存在曾經出現過的n，
// 如果再出現代表會成為無限循環，就結束，最後看結果是不是1
var isHappy = function(n) {
    var list = [];

    while (!list.includes(n) && n !== 0) {
        list.push(n)
        n = Number(n.toString().split('').reduce((acc, cur) => acc + (cur * cur), 0))
    }
    return n === 1;
};
//這個寫法測資勝過36%的人，算是比較弱一點的，

//所以我找了一個滿特別的演算法，並以javascript實作
var isHappy = function(n) {
    while (n > 4) 
        n = Number(n.toString().split('').reduce((acc, cur) => acc + (cur * cur), 0))
    return n === 1;
};
// 這個寫法在測資裡，勝過了97%的人，有趣的是， 
// 把n轉成數字再比較，可以多勝過約35%的人
