// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    int find_blank(vector<vector<char>>& A,int& row,int& column){
        for(row=0;row<9;++row){
            for(column=0;column<9;++column){
                if(A[row][column]=='.') return 1;
            }
        }
        return 0;
    }
    int isvalid(int b[3][3][9],int r[9][9],int c[9][9],int i,int j,int x){
        if(b[i/3][j/3][x-1]==0 && r[i][x-1]==0 && c[j][x-1]==0)
        return 1;
        else return 0;
    }
    int sudoku(int b[3][3][9],int r[9][9],int c[9][9],vector<vector<char>>& A){
        int row, column;
        if(find_blank(A,row,column)==0) return 1;   
        for(int i=1;i<10;++i){
            if(isvalid(b,r,c,row,column,i)==1){
                A[row][column] = (char)(i+48);
                b[row/3][column/3][i-1]=1,r[row][i-1]=1,c[column][i-1]=1;
                if(sudoku(b,r,c,A)==1) return 1;
                A[row][column] = '.';
                b[row/3][column/3][i-1]=0,r[row][i-1]=0,c[column][i-1]=0;
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> A = board;
        int b[3][3][9];
        int r[9][9];
        int c[9][9];
        for(int i=0;i<3;++i) for(int j=0;j<3;++j) for(int k=0;k<9;++k) b[i][j][k] = 0;
        for(int i=0;i<9;++i) for(int j=0;j<9;++j) r[i][j]=0,c[i][j]=0;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(A[i][j]!='.'){
                    r[i][A[i][j]-'0'-1] = 1;
                    c[j][A[i][j]-'0'-1] = 1;
                    b[i/3][j/3][A[i][j]-'0'-1] = 1;
                }
            }
        }
        int a = sudoku(b,r,c,A);
        board = A;
    }
};
