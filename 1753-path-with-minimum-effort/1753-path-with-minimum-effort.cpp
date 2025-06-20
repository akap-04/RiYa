class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>> 
        > pq;

        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));

        dis[0][0]=0;
        pq.push({0,{0,0}});

        int dr[]={0,1,0,-1},dc[]={1,0,-1,0};

        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first,r=it.second.first,c=it.second.second;
            pq.pop();
            if(r==n-1 && c==m-1) return diff;
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newdiff=max(abs(heights[r][c]-heights[nr][nc]),diff);
                    if(newdiff<dis[nr][nc]){
                        dis[nr][nc]=newdiff;
                        pq.push({newdiff,{nr,nc}});
                    }
                }
            }
        }
        return 0;
        
    }
};