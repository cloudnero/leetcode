Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...






void solveSudoku(vector<vector<char> > &board) {
        sudoku(board);
    }

    bool check(vector<vector<char> > &board, int a, int b){
        for(int i = 0; i < 9; i++){
            if(i != b && board[a][i] == board[a][b]) 
                return false;
            if(i != a && board[i][b] == board[a][b])
                return false;
        }
        
        int i = a / 3 * 3, j = b / 3 * 3;
        for(int m = 0; m < 3; m++)
            for(int n = 0; n < 3; n++){
                if(m+i != a && n+j != b && board[m+i][n+j] == board[a][b])
                    return false;
            }
        return true;
    }
    bool sudoku(vector<vector<char> > &board){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(int k = 1; k <= 9; k++){
                        board[i][j] = k + '0';
                        if(check(board, i, j) && sudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        return true;
    }
