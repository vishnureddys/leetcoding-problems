
class Solution {
public:
    int helper(vector<vector<int>>& grid, int i,int j, vector< vector<int> > &cost) {      
        if( i < 0 || j < 0 || i == grid.size() || j == grid[0].size() )
            return INT_MAX;
        if( i == 0 && j == 0)
            return grid[i][j];
        if( cost[i][j] != INT_MAX  )
            return cost[i][j];
        cost[i][j] =  grid[i][j] + min( helper(grid,i-1,j,cost) , helper(grid,i,j-1,cost)  );
        return cost[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {  
        int n = grid.size();
        int m = grid[0].size();        
        vector< vector<int> > cost(n, vector<int>(m,INT_MAX));
        return helper(grid,n-1,m-1,cost);
    }
};