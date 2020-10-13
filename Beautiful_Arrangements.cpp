/*Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

    The number at the ith position is divisible by i.
    i is divisible by the number at the ith position.

 

Now given N, how many beautiful arrangements can you construct?
*/
class Solution {
public:
    int countArrangement(int N) {
        vector<int> visited(N+1, 0);
        dfs(1, visited, N);
        return res;
    }
    void dfs(int pos, vector<int>& visited, int N){
        if(pos == N+1){
            res++;
            return;
        }
        for(int i=1; i<=N; i++){
            if((!(i%pos) || !(pos%i)) && !visited[i]){
                visited[i] = 1;
                dfs(pos+1, visited, N);
                visited[i] = 0;
            }
        }
        
    }
private:
    int res=0;
};