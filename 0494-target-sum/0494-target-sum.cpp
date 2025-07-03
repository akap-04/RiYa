class Solution {
public:
    int findpaths(vector<int>& nums,int tar){
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(nums[0]!=0 && nums[0]<=tar) dp[0][nums[0]]=1;

        

        for(int i=1;i<n;i++){
            for(int t=0;t<=tar;t++){
                int notpick=dp[i-1][t];
                int pick=0;
                if(nums[i]<=t)pick=dp[i-1][t-nums[i]];

                dp[i][t]=pick+notpick;
            }
        }
        return dp[n-1][tar];
    }

    int cntpaths(int d, vector<int>&nums){
        int total=0;
        for(auto &it:nums)total+=it;

        //if(total-d || (total-d)%2) return 0;
        if (total < abs(d) || (total + d) % 2 != 0) return 0;
        int subsetSum = (total + d) / 2;
        return findpaths(nums,subsetSum);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
       return cntpaths(target,nums);
    }
};