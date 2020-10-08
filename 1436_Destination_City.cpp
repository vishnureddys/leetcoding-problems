// https://leetcode.com/problems/destination-city/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> hashmap;
        for(int i=0;i<paths.size();i++) {
            hashmap[paths[i][0]]++;
        }
        
        for(int i=0;i<paths.size();i++) {
            if(hashmap.count(paths[i][1]) <= 0) {
                return paths[i][1];
            }
        }
        
        return "";
    }
};