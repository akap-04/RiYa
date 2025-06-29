class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                     int up=0,l=0;
                    if(i>0){
                        up=grid[i][j]+dp[i-1][j];
                    }else{
                        up+=1e9;
                    }
                    if(j>0){
                          l=grid[i][j]+dp[i][j-1];
                    }else{
                        l+=1e9;
                    }
                    dp[i][j]=min(up,l);
                }
            }
        }
        return dp[m-1][n-1];

    }
};