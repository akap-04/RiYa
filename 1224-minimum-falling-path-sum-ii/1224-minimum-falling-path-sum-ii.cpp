class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int j=0;j<=n-1;j++) dp[0][j]=grid[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini = INT_MAX;
                for (int t = 0; t < n; t++) {
                     if (t != j) {
                         mini = min(mini, dp[i-1][t]);
                         }
                    }
                dp[i][j] = grid[i][j] + mini;

                //if(j+1<n)rd=grid[i][j]+dp[i-1][j+1];
                //else rd=1e9;

             
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};