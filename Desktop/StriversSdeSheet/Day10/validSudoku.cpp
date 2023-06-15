bool isSafe(int matrix[][9], int row, int col, int ch){
    for(int i=0;i<8;i++){
        if(matrix[row][i]==ch) return false;
        if(matrix[i][col]==ch) return false;
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
    }
    return true;
}

bool solve(int matrix[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){        
                for(int ch=1;ch<=9;ch++){
                    if(isSafe(matrix,i,j,ch)){
                        matrix[i][j] = ch;
                        if (solve(matrix) == true) {
                          return true;
                        } 
                        else matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
        
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    solve(matrix);
}
