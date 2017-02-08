/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
/**
題目:給定一個 number[] , 找出index1跟index2
使得number[index1]+number[index2] = target
且index2>index1
 */
//不會過，因為超過time limit
var twoSum = function(numbers, target) {
    var resA = 0;
    var resB = 0;
    numbers.find((numA, index1) => {
        numbers.find((numB, index2) => {
            if (numA + numB === target && index2 > index1) {
                resA = index1 + 1;
                resB = index2 + 1;
            }
        })
    })
    return [resA, resB];
};
//縮小迴圈範圍，過了，但測資表現極差 O(n^2)
var twoSum = function(numbers, target) {
    var resA = 0;
    var resB = 0;
    var len = numbers.length;
    for (var numA = 0; numA < len; numA++) {
        for (var numB = numA + 1; numB < len; numB++) {
            if (numbers[numA] + numbers[numB] === target) {
                resA = numA + 1;
                resB = numB + 1;
                break;
            }
        }
    }
    return [resA, resB];
};
//題目已經先保證必有解，並且給的數列是排序號的，可以用優化過的二分法
//左右夾擊，如果二個數字相加 > 目標，代表第二個數字太大了，如果小於問標，代表第一個數字太小了
//O(n)
//解到今天為止，有個感想，用三元運算子，雖然提升的效能我不確定有多少，但絕對能讓你的成績勝過很多人
var twoSum = function(numbers, target) {
    var i = 0
    var j = numbers.length - 1;
    while (numbers[i] + numbers[j] !== target) {
        numbers[i] + numbers[j] > target ? j-- : i++
    }
    return [i + 1, j + 1];
}
