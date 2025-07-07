class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n);
       string s(n,'.');
       for(int i=0;i<n;i++){
        board[i]=s;
       }

       vector<int> left(n,0);
       vector<int> Udia(2*n-1,0);
       vector<int> Ldia(2*n-1,0);

       sol(0,board,ans,left,Udia,Ldia,n);
       return ans;
    }

    void sol(int c,vector<string>&board,vector<vector<string>>&ans,vector<int> &left,vector<int> &Udia,vector<int> &Ldia,int n){
        if(c==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(left[i]==0 && Ldia[i+c]==0 && Udia[n-1+c-i]==0){
                board[i][c]='Q';
                left[i]=1;
                Ldia[i+c]=1;
                Udia[n-1+c-i]=1;

                sol(c+1,board,ans,left,Udia,Ldia,n);

                board[i][c]='.';
                left[i]=0;
                Ldia[i+c]=0;
                Udia[n-1+c-i]=0;
            }
        }
    }
};