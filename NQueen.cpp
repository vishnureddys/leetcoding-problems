// https://leetcode.com/problems/n-queens/

class Solution {
public:
    int isvalid(int i,int j, int A,int r[],int c[],int d1[],int d2[]){
        if(r[i]==0 && c[j]==0 && d1[i+j]==0 && d2[i-j+A-1]==0) return 1;
        else return 0;
    }
    void nqueen_util(int A,int row,vector<vector<string>>& result,vector<string> &v,int r[],int c[],int d1[],int d2[]){
        if(row==A){
            result.push_back(v);
            return;
        }
        string temp = "";
        for(int i=0;i<A;++i) temp.push_back('.'); 
        for(int i=0;i<A;++i){
            if(isvalid(row,i,A,r,c,d1,d2)==1){
                temp[i] = 'Q';
                r[row]=1,c[i]=1,d1[i+row]=1,d2[row-i+A-1]=1;
                v.push_back(temp);
                nqueen_util(A,row+1,result,v,r,c,d1,d2);
                temp[i] = '.';
                r[row]=0,c[i]=0,d1[i+row]=0,d2[row-i+A-1]=0;
                v.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        int A = n;
        vector<vector<string>> result;
        vector<string> v;
        int r[100] = {0};
        int c[100] = {0};
        int d1[2*100-1] = {0};
        int d2[2*100-1] = {0};
        nqueen_util(A,0,result,v,r,c,d1,d2);
        return result;
    }
};
