// 36. Valid Sudoku

class Solution {
public:
    bool validRow(vector<vector<char>>& board, vector<int> norm, int index){
        for (int i = 0; i < 9; i++){
            if (board[index][i] != '.'){
                // ASCII, from char to int -48, -1 for index in vector
                if (norm[board[index][i]-49] == 0)
                    norm[board[index][i]-49]++;
                else
                    return false;
            } 
        }
        return true;
    }
    
    bool validCol(vector<vector<char>>& board, vector<int> norm, int index){
        for (int i = 0; i < 9; i++){
            if (board[i][index] != '.'){
                if (norm[board[i][index]-49] == 0)
                    norm[board[i][index]-49]++;
                else
                    return false;
            } 
        }
        return true;
    }
    
    bool validBox(vector<vector<char>>& board, vector<int> norm, int index){
        // i:012345678 -> 00 03 06 30 33 36 60 63 66
        int row = (index/3)*3;
        int col = (index%3)*3;
        
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i+row][j+col] != '.'){
                    if (norm[board[i+row][j+col]-49] == 0)
                        norm[board[i+row][j+col]-49]++;
                    else
                        return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> norm = {0,0,0,0,0,0,0,0,0};
        
        for (int i = 0; i < 9; i++){
            if (validRow(board,norm,i) && validCol(board,norm,i) && validBox(board,norm,i))
                continue;
            else
                return false;
        }
        
        return true;
    }
};
