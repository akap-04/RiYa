class Solution {
public:

    void dfs(int r,int c,vector<vector<char>>& arr){
        int n=arr.size(), m=arr[0].size();
        if(r<0 || r>=n || c<0 || c>=m ) return;
        if(arr[r][c]=='.') return;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        arr[r][c]='.';//marking visted
        for(int i=0;i<4;i++){
            dfs(r+dr[i],c+dc[i],arr);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
       int n=board.size(), m=board[0].size();
       if(n==0) return 0;

       int cnt =0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='X'){
                cnt++;
                dfs(i,j,board);
            }
        }
       }

    return cnt;

    }
};