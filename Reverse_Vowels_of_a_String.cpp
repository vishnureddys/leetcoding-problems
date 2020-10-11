/* Write a function that takes a string as input and reverse only the vowels of a string.
*/
class Solution {
public:
    bool isVowels(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int n=s.size();
        if(n==1)
            return s;
        int i=0, j=n-1;
        while(i<j){
            if(isVowels(s[i]) && isVowels(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else{
                if(!isVowels(s[i]))
                    i++;
                if(!isVowels(s[j]))
                    j--;
            }
        }
        return s;
    }
};