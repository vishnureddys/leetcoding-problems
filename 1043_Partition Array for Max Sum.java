/* Leetcode Problem : #1043 

Problem statement : Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. 
After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning
*/

class Solution {

    public int maxSumAfterPartitioning(int[] arr, int k) {
        int dp[] = new int[arr.length];
        return solve(arr, 0, arr.length, k, dp);

    }

    public int solve(int arr[], int src, int end, int k, int dp[]) {
        if (src >= end) {
            return 0;
        }

        if (dp[src] != 0) {
            return dp[src];
        }

        int maxAns = -1, max = -1;

        for (int i = src; i < Math.min(src + k, end); i++) {
            for (int j = src; j <= i; j++) {
                if (arr[j] > max) {
                    max = arr[j];
                }
            }
            int val = max * (i - src + 1) + solve(arr, i + 1, end, k, dp);
            maxAns = Math.max(maxAns, val);
        }

        dp[src] = maxAns;
        return maxAns;

    }
}
