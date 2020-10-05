// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> ma;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            ma[str].push_back(strs[i]);
        }
        for(auto i:ma){
            ans.push_back(i.second);
        }
        return ans;
    }
};