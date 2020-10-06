// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        string A = s;
        int n = A.length();
        // int m = 1;
        long long int dp[105];
        if((int(A[0])-48)==0) return 0;
        dp[0] = 1;
        if(n==1) return 1;
        if((int(A[1])-48)==0){
            if((int(A[0])-48)<=2) dp[1] = 1;
            else return 0;
        }
        else{
            if(((int(A[0])-48)==1)||((int(A[0])-48)==2 && (int(A[1])-48)<7)) dp[1] = 2;
            else dp[1] = 1;
        }
        for(int i=2;i<n;++i){
            if((int(A[i])-48)==0){
                if((int(A[i-1])-48)==1 || (int(A[i-1])-48)==2) dp[i] = dp[i-2];
                else return 0;
            }
            else{
                if(((int(A[i-1])-48)==1)||((int(A[i-1])-48)==2 && (int(A[i])-48)<7)) 
                    dp[i] = (dp[i-2]+dp[i-1]);
                else dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};
