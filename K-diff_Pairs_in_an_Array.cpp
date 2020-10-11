/* Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

    0 <= i, j < nums.length
    i != j
    |nums[i] - nums[j]| == k

Notice that |val| denotes the absolute value of val.
*/
class Solution {
public:
    
    unordered_map<int,bool>vis2;
    unordered_map<int,int>vis ;
    int findPairs(vector<int>& nums, int k) {
        for(auto i : nums )
        {
            ++vis[i] ;
            vis2[i] = 1 ;
        }
        int ans = 0 ; 
        for( auto i : nums )
        {
            if(!vis2[i]) continue ;
            if(  vis[-(k-i)]  )
            {
                if( ( i == -(k-i) && vis[i] > 1 )  || -(k-i) != i ) ++ ans ;  
            }
            vis2[i] = 0 ;
        }
        return ans ;
    }
};