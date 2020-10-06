//https://leetcode.com/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int total_sum = 0;
        int n= nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            total_sum += nums[i];
        }
        if(S > total_sum)return 0;
        if((S + total_sum)%2 != 0){
            return 0;
        }else{
            int s1 = S + total_sum;
            s1 = s1/2;
            int dp[n+1][s1 + 1];
            for(int i = 0 ;i <= s1 ; i++){
                dp[0][i] = 0;
            }
            dp[0][0] = 1;
            for(int i = 1 ; i <= n ; i++){
                if(nums[i-1] == 0){
                    dp[i][0] = dp[i-1][0]*2 ;
                }else{
                    dp[i][0] = dp[i-1][0];
                }
            }
            for(int i = 1 ; i <= n ; i++ ){
                for(int j = 1 ; j <= s1 ; j++){
                    if(nums[i-1] > j){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                    }
                }
            }
            return dp[n][s1];
        }
    }
};