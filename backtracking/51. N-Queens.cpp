
/*
題目:https://leetcode.com/problems/n-queens/
題意:經典八皇后問題，改為n皇后
思路:驗證格子是否合法是此題關鍵，
其餘就是一般的回溯，其次就是回傳的要求是二維容器
目標是收集一維的答案集，放進二維容器即可
*/
class Solution {
public:
    vector<vector<string>>result;
    vector<vector<string>> solveNQueens(int n) {
        // n * n 
        vector<string> chessboard(n,string(n, '.'));
        backtracking(n,0,chessboard);
        return result;
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