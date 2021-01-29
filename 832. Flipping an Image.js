/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function (A) {
    return invert(flip(A));
};
/**
 *
 *
 * @param {*} A
 */
function flip(A) {
    return A.map(numArr => numArr.reverse())
}
function invert(A) {
    return A.map(numArr => numArr.map(num => num == 0 ? 1 : 0))
}

// Runtime: 80 ms, faster than 90.61% of JavaScript online submissions for Flipping an Image.
// Memory Usage: 40.2 MB, less than 5.22% of JavaScript online submissions for Flipping an Image.