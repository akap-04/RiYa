class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        int n=image.size(),m=image[0].size();
        vector<vector<int>> ans=image;

        dfs(image,ans,sr,sc,inicolor,color);
        return ans;
    }


    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int r,int c,int inicolor, int color){
        int n=image.size(),m=image[0].size();
        ans[r][c]=color;
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];

            if(nr>=0 && nr<n &&  nc>=0 && nc<m
            && image[nr][nc]==inicolor && ans[nr][nc]!=color ){
                dfs(image,ans,nr,nc,inicolor,color);
            }
        }
    }
};