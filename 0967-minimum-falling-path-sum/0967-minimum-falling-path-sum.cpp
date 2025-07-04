class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int j=0;j<=n-1;j++) dp[0][j]=matrix[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int s=matrix[i][j]+dp[i-1][j],ld=0,rd=0;
                if(j-1>=0)ld=matrix[i][j]+dp[i-1][j-1];
                else ld=1e9;

                if(j+1<n)rd=matrix[i][j]+dp[i-1][j+1];
                else rd=1e9;

                dp[i][j]=min(s,min(ld,rd));
            }
        }

        int mini=dp[n-1][0];
        for(int j=1;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};