class Solution {
public:

    void bfs(int i,int j, vector<vector<char>>& grid ,vector<vector<int>>& vis){
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n=grid.size(), m=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr >=0 && nr < n && nc >=0 && nc < m &&
                !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size(), m=grid[0].size();
       if(n==0) return 0; 

       vector<vector<int>> vis (n,vector(m,0));
        
       int cnt=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                cnt++;
                bfs(i,j,grid,vis);
                
            }
        }
       }
       return cnt;
    }
};