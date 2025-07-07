class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int area=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int cnt=0;
                    dfs(i,j,vis,grid,cnt,n,m);
                    area=max(area,cnt);
                    
                }
            }
        }
        
        return area;
    }
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int& cnt, int n, int m){
        vis[i][j]=1;
        cnt++;

        int dr[]={0,1,0,-1},dc[]={1,0,-1,0};
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, vis, grid, cnt, n, m);
            }
        }
    }
};