// 1 2 3 4 5
// =============
// 12 13 14 15
// 21 23 24 25
// 31 32 34 35
// 41 42 43 45
// 51 52 53 54
// ============

// 123 124 125
// 132 134 135
// 142 143 145
// 152 153 154
// ===========

// 12345 12354
// 12435 12453
// 12534 12543
const basic = [1, 2, 3, 4, 5];
const basicArr = [[1], [2], [3], [4], [5]];

basicArr.forEach(arr => {
    let flag = 0;
    let ans
    while (flag < 5) {
        ans = sub(arr)
        ans = ans.map(arr => sub(arr).map(arr => sub(arr).map(arr => sub(arr))))
        flag = flag + 1
    }
    console.log('ans = ', ans[0])

})




function sub(arr) {
    let newArr = [];
    basic.forEach(num => {
        let isInclude = arr.includes(num);
        if (!isInclude) {
            let tempArr = JSON.parse(JSON.stringify(arr));
            tempArr.push(num)
            newArr.push(tempArr);
        }
    })
    return newArr;
}