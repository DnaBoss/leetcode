
/**
 * 題目:Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 * 題意: 驗證一個 9*9的陣列是否符合數獨的規則
 * 思路: 記錄行、記錄列、記錄各區塊是否出現過一樣的數字，有就不合規則，沒有就合規則
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
    let row = {};
    let col = {};
    let block = {};
    for (let rowIndex = 0; rowIndex <= board.length - 1; rowIndex++) {
        row[rowIndex] = row[rowIndex] || {};
        for (let colIndex = 0; colIndex <= board[rowIndex].length - 1; colIndex++) {
            col[colIndex] = col[colIndex] || {};
            let num = board[rowIndex][colIndex];
            if (num == '.') {
                continue;
            }
            let zone = 0;
            Object.keys(blockTable).find(flag => {
                let area = blockTable[flag];
                if (rowIndex >= area[0] && rowIndex <= area[1] && colIndex >= area[2] && colIndex <= area[3]) {
                    zone = flag;
                }
            })
            block[zone] = block[zone] || {}
            if (row[rowIndex][num] || col[colIndex][num] || block[zone][num]) {
                console.log('block = ', block)
                return false;
            }
            row[rowIndex][num] = true;
            col[colIndex][num] = true;
            block[zone][num] = true;
        }
    }
    return true;
};
// 此表可以程式動態生成
const blockTable =
{
    1: [0, 2, 0, 2],
    2: [3, 5, 0, 2],
    3: [6, 8, 0, 2],
    4: [0, 2, 3, 5],
    5: [3, 5, 3, 5],
    6: [6, 8, 3, 5],
    7: [0, 2, 6, 8],
    8: [3, 5, 6, 8],
    9: [6, 8, 6, 8]
}
let board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
isValidSudoku(board)
// 測資結果 
// Runtime: 96 ms, faster than 80.78% of JavaScript online submissions for Valid Sudoku.
// Memory Usage: 43.2 MB, less than 8.75% of JavaScript online submissions for Valid Sudoku.
