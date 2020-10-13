class Solution {
    public int uniquePaths(int m, int n) {
        int[][] asd = new int[2][n];
        Arrays.fill(asd[1], 1);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                
                if (i == 0 ){
                    asd[0][j] = 1;
                } else if ( j != 0){
                    asd[1][j] = asd[0][j] + asd[1][j-1];
                    asd[0] = asd[1];
                }
                
                
            }    
        }
        return asd[1][n-1];
    }
}