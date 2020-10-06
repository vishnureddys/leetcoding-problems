// https://leetcode.com/problems/text-justification/

class Solution {
public:
    string gen_space(int i){
    string s = "";
    while(i--) s += " ";
    return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> A = words;
        int B = maxWidth;
        int n = A.size();
        int l[n];
        for(int i=0;i<n;++i) l[i] = A[i].length();
        vector<int> store;
        int count = 0;
        int length = 0;
        for(int i=0;i<n;++i){
            count += l[i];
            ++length;
            if(count+length-1>B){
                store.push_back(i-1);
                count = l[i];
                length = 1;
            }
        }
        store.push_back(n-1);
        vector<string> result(store.size(),"");
        vector<string> s;
        if(n==0) return s;
        int prev = -1;
        for(int i=0;i<store.size()-1;++i){
            count = 0;
            if(store[i]-prev==1){
                result[i] += A[store[i]];
                result[i] += gen_space(B-l[store[i]]);
            }
            else{
                for(int j=prev+1;j<=store[i];++j) count += l[j];
                int space = B-count;
                int qoutient = space/(store[i]-prev-1);
                int remain = space%(store[i]-prev-1);
                string temp = gen_space(qoutient);
                while(prev<store[i]-1){
                    result[i] += A[++prev];
                    result[i] += temp;
                    if(remain-->0){
                        result[i] += " ";
                    }
                }
                result[i] += A[store[i]];
            }
            prev = store[i];
        }
        while(prev<n-2){
            result[store.size()-1] += A[++prev];
            result[store.size()-1] += " ";
        }
        result[store.size()-1] += A[n-1];
        result[store.size()-1] += gen_space(B-result[store.size()-1].length());
        return result;
    }
};
