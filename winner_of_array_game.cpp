// https://leetcode.com/problems/find-the-winner-of-an-array-game/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int j = 0;
        int count = 0;
        for(int i = 1;i<arr.size();i++){
            if(arr[j]<arr[i]){
                j = i;
                count = 0;
            }
            count++;
            if(count == k)
                break;
        }
        return arr[j];
    }
};