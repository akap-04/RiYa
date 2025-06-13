class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        queue<pair<int,pair<int,int>>> q;//(dist,r,c)
        q.push({1,{0,0}});
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first, r=it.second.first, c=it.second.second;

             

            for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                int nr=r+dr, nc=c+dc;

                if(nr>=0 && nr<n && nc>=0 && nc<n
                && grid[nr][nc]==0 && d+1<dist[nr][nc]){
                    dist[nr][nc]=d+1;
                    if(nr==n-1 && nc==n-1) return d+1;
                    q.push({d+1,{nr,nc}});
                }
            }
        }
        }

        return -1;
    }
};