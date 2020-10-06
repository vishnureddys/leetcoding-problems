class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n=A.size();
        if(n==2){
            if(A[0]<=A[1]){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        vector<int> max_val(n);
        max_val[0]=A[0];
        for(int i=1;i<n;i++){
            if(A[i]>max_val[i-1]){
                max_val[i]=A[i];
            }
            else{
                max_val[i]=max_val[i-1];
            }
        }
        vector<int> min_val(n);
        min_val[n-1]=A[n-1];
        min_val[n-2]=A[n-1];
        for(int i=n-3;i>=0;i--){
            if(min_val[i+1]<A[i+1]){
                min_val[i]=min_val[i+1];
            }
            else{
                min_val[i]=A[i+1];
            }
        }
        int index=-1;
        for(int i=0;i<n;i++){
            if(max_val[i]<=min_val[i]){
                index=i;
                break;
            }
        }
        return index+1;
        
    }
};
