class Solution {
public:

    int dfs(int r, int c,vector<vector<int>>&grid,vector<vector<int>>&vis,int empty){
        int n=grid.size(),m=grid[0].size();
        if(grid[r][c]==2){
            return empty==0? 1:0;
        }
        if (r<0 || r>=n || c<0 || c>=m || vis[r][c] || grid[r][c]==-1) return 0;
        
        vis[r][c]=1;
        int cnt=0;
        int dr[]={1,0,-1,0},dc[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m &&
            !vis[nr][nc] ){
                cnt+=dfs(nr,nc,grid,vis,empty-1);
                

            }
        }
        vis[r][c]=0;
        return cnt;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
       int n=grid.size(),m=grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));
       int r=-1,c=-1,empty=0;

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            //if(grid[i][j]==-1) return 0;
            if(grid[i][j]==1){
              r=i,c=j;
            }
            if(grid[i][j]==0){
                empty++;
            }
        }
       } 
       return dfs(r,c,grid,vis,empty+1);
    }
};