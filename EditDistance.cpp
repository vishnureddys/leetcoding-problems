// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        string A = word1;
        string B = word2;
        int n = A.length();
        int m = B.length();
        int store[n+1][m+1];
        store[0][0] = 0;
        int temp;
        for(int i=1;i<n+1;++i) store[i][0] = i;
        for(int i=1;i<m+1;++i) store[0][i] = i;
        for(int i=1;i<n+1;++i){
            for(int j=1;j<m+1;++j){
                temp = min(store[i-1][j]+1,store[i][j-1]+1);
                store[i][j] = min(temp,store[i-1][j-1]+(int)(A[i-1]!=B[j-1]));
            }
        }
        return store[n][m];
    }
};
