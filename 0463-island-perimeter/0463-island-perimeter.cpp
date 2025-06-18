class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int l=0;
        int n=grid.size(),m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    l+=4;
                    if(i>0 && grid[i-1][j]==1){
                        l-=2;
                    }
                    if(j>0 && grid[i][j-1]==1){
                        l-=2;
                    }
                }
                
            }
        }
        return l;
    }
};