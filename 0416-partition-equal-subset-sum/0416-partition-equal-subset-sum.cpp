class Solution {
public:
    bool iftrue(vector<int>& nums,int sum){
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if (nums[0] <= sum) dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int k=1;k<=sum;k++){
                bool nottake=dp[i-1][k];
                bool take=false;
                if(nums[i]<=k)take=dp[i-1][k-nums[i]];

                dp[i][k]=take|nottake;
            }
        }
        return dp[n-1][sum];
        
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];

        }
        if(s%2) return false;
        int s1=s/2;
        return iftrue(nums,s1);
    }
};