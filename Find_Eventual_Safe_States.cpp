https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:

     bool iscycle(int i,vector<bool>&temp1,vector<bool>&temp2,vector<vector<int>>& graph,vector<int>&dp)
     {
         if(dp[i]!=-1)
         {
             return dp[i];
         }
         if(!temp1[i])
         {
             temp1[i]=true;
             temp2[i]=true;
             for(auto j:graph[i])
             {
                 if(!temp1[j]&&iscycle(j,temp1,temp2,graph,dp))
                 {
                     dp[i]=1;
                     return true;
                 }
                 else if(temp2[j])
                 {
                     dp[i]=1;
                     return true;
                 }
             }
         }
         temp2[i]=false;
         dp[i]=0;
         return false;
     }
    
     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     
     vector<int> ans;
     int n=graph.size();
     vector<bool> temp1 (n);
     vector<bool> temp2 (n);
     vector<int> dp(n, -1); 
      
     for(int i=0;i<n;i++)
     {
         temp1[i]=false;
         temp2[i]=false;
     }
     
     for(int i=0;i<n;i++)
     {
         if(!iscycle(i,temp1,temp2,graph,dp))
         {
             ans.push_back(i);
         }
     }
     
     return ans;
    }
};
