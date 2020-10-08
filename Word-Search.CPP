// Problem - 79.Word Search
// Problem link - https://leetcode.com/problems/word-search/
// @author - sushant19-99


class Solution
{
    public:
    bool dfs(vector<vector<char>>& board, string word, int i, int row, int col){
        if(i==word.size())return true;
        if(row>=board.size() || col>=board[0].size() || row<0 || col<0)return false;
        if(board[row][col]!=word[i])return false;
          board[row][col]='-1';
        bool ans = dfs(board,word,i+1,row,col+1) ||
               dfs(board,word,i+1,row+1,col) ||
               dfs(board,word,i+1,row,col-1) ||
               dfs(board,word,i+1,row-1,col);
        board[row][col]=word[i];
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool found=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0])
                    found = dfs(board,word,0,i,j);
                if(found)return true;
            }
        }
        return false;
    }
};
