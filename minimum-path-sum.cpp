//https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long dp[n][m];
        memset(dp, 1000000 , sizeof(dp));
        dp[0][0] = grid[0][0];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(j - 1 >= 0)dp[i][j] = min(dp[i][j] , dp[i][j-1] + grid[i][j]);
                if(i - 1 >= 0)dp[i][j] = min(dp[i][j] , dp[i -1][j]+ grid[i][j]);
            }
        }
        return dp[n-1][m-1];
    }
};