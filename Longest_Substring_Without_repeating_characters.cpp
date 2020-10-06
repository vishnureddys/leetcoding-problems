// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n<2) return n;
        int left=0;
        int right=0;
        int max_len=0;
        set<char> st;
        while(right<n){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
                max_len=max(max_len,(int)st.size());
                right++;
            }
            else{
                st.erase(s[left]);
                left++;
                
            }
        }
        return max_len;
    
    }
    
    };
