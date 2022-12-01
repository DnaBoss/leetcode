
/*
題目:https://leetcode.com/problems/n-queens-ii/description/
題意:經驗8皇后，改為n 皇后
思路:照抄51題，把答案由二維容器，改為所有子答案集的數
*/
class Solution {
public:
    vector<vector<string>>result;
    int totalNQueens(int n) {
        // n * n 
        vector<string> chessboard(n,string(n, '.'));
        backtracking(n,0,chessboard);
        return result.size();
    }

     void backtracking(int n,int row,vector<string>& chessboard){
        if(row == n){
            result.push_back(chessboard);
            return;
        }

        for(int col = 0;col < n;col++){
            if(isVlidate(row,col,chessboard,n)){
                chessboard[row][col] = 'Q';
                backtracking(n,row + 1 ,chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    bool isVlidate(int row,int col,vector<string>& chessboard,int n){
        for(int i = 0;i < row; i++){
            if(chessboard[i][col] == 'Q'){
                return false;
            }
        }
        // 檢查 「\」 這個斜角上的格子
        for(int i = row - 1,j = col - 1;i >=0 && j >= 0; i--,j--){
            if(chessboard[i][j] == 'Q'){
                return false;
            }
        }
        // 檢查 「/」 這個斜角上的格子
        for(int i = row -1,j = col + 1 ;i >= 0 && j < n; i--,j++){
            if(chessboard[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
};