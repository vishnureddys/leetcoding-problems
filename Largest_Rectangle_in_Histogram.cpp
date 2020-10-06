//https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {  
vector<int> msl(vector<int> A)
{
    vector<int> v;
    stack<pair<int,int>> s;
    for(int i=0;i<A.size();i++)
    {
        if(s.empty())
        {
            v.push_back(-1);
        }
        else if(s.top().first<A[i])
        {
            v.push_back(s.top().second);
        }
        else if(!s.empty()&&s.top().first>=A[i])
        {
        while(!s.empty()&&s.top().first>=A[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            v.push_back(-1);
        }
        else if(s.top().first<A[i])
        {
            v.push_back(s.top().second);
        }
        }
        s.push({A[i],i});
    }
    return v;
}

vector<int> msr(vector<int> A)
{
    vector<int> v;
    stack<pair<int,int>> s;
    for(int i=A.size()-1;i>=0;i--)
    {
        if(s.empty())
        {
            v.push_back(A.size());
        }
        else if(s.top().first<A[i])
        {
            v.push_back(s.top().second);
        }
        else if(!s.empty()&&s.top().first>=A[i])
        {
        while(!s.empty()&&s.top().first>=A[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            v.push_back(A.size());
        }
        else if(s.top().first<A[i])
        {
            v.push_back(s.top().second);
        }
        }
        s.push({A[i],i});
    }
    reverse(v.begin(),v.end());
    return v;
}    
    
public:
    int largestRectangleArea(vector<int>& heights){
    vector<int> x,y;
    x=msl(heights);
    y=msr(heights);
    int ans=0;
    for(int i=0;i<heights.size();i++)
    {
      ans=max(ans,((y[i]-x[i]-1)*heights[i]));
    }
    return ans;   
    }
};
