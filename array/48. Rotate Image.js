/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    let len = matrix.length;
    for (let row = 0; row < (len >> 1); row++) {
        for (let col = row; col < len - 1 - row; col++) {
            swap(matrix, row, col, col, len - 1 - row)
            swap(matrix, row, col, len - 1 - row, len - 1 - col)
            swap(matrix, row, col, len - 1 - col, row)
        }
    }
};

function swap(matrix, row1, col1, row2, col2) {
    matrix[row1][col1] = matrix[row1][col1] + matrix[row2][col2];
    matrix[row2][col2] = matrix[row1][col1] - matrix[row2][col2];
    matrix[row1][col1] = matrix[row1][col1] - matrix[row2][col2];
}