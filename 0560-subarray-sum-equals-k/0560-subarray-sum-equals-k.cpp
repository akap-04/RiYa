class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;//psum,cnt
        mp[0]=1;
        int sum=0,cnt=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())cnt+=mp[sum-k];
            mp[sum]++;

        }
        return cnt;
        
    }
};