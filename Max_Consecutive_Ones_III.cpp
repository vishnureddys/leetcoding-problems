class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int count = 0, i = 0, j = 0;
        int res = INT_MIN;

 

        for (i = 0; i < A.size(); i++) {
            if (A[i] == 0) count++;  /* have some hashmap or counter */

 

            /* Loop inside for to reduce the window size based on constraint */
            while (count > K && j < A.size()) {
                if (A[j] == 0)
                    count--;
                j++;
            }

 

            /* get the maximum value of the window which satisfies the constraint */
            res = max(res, i-j+1);
        }

 

        return res == INT_MIN ? ((count <= K) ? A.size() : 0) : res; 
    }
};