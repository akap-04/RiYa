class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n=grid.size() , m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector(m,0));
        int freshcnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }else{
                    vis[i][j]=0;
                }

                if(grid[i][j]==1) freshcnt++;
            }
        }

        int tm=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;

            tm=max(tm,t);
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr >=0 && nr < n && nc >=0 && nc < m &&
                !vis[nr][nc] && grid[nr][nc]==1){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=1;
                    cnt++;
                }
            }
        }
        if(cnt!=freshcnt) return -1;
        return tm;
    }
};