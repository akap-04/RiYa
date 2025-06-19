class Solution {
public:


    void dfs(int r, int c, vector<vector<int>>& board, vector<vector<int>>& vis){
         int n=board.size(),m=board[0].size();
        vis[r][c]=1;
        int dr[]={0,1,0,-1},dc[]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m
            && !vis[nr][nc] && board[nr][nc]==1){
                dfs(nr,nc,board,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
       int n=grid.size(),m=grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,grid,vis);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,grid,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,grid,vis);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};