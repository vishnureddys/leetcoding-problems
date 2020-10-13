// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int swap = 0;
        int right[grid.size()];
        for(int i = 0;i<grid.size();i++){  
            int k = -1;
            for(int j=0;j<grid.size();j++){
                if(grid[i][j] == 1)
                    k = j;          
                
            }
            right[i] = k;
            
            
        }
        int n = grid.size();
        
        for(int i = 0;i<grid.size();i++){
            if(right[i]<=i)
                continue;
            else{
                int j = i +1;
                while(j<n&& !(right[j]<=i))
                {
                    j++;
                }
                // swaps
                if(j==n)
                {
                 swap = -1;
                    break;
                }
                int k = j;
                while(k>i){
                    int temp = right[k-1];
                    right[k-1] = right[k];
                    right[k] = temp;
                    swap++;
                    k--;
                }
                
            }
        }
        return swap;
        
    }
};