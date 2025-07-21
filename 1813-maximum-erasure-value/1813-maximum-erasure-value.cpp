class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        unordered_set<int>mpp;
        long long maxsum=0,sum=0;
        while(r<n){
            if (mpp.find(nums[r]) == mpp.end()) {
                
                mpp.insert(nums[r]);
                sum += nums[r];
                maxsum = max(maxsum, sum);
                r++;
            } else {
               
                mpp.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
        }
        return static_cast<int>(maxsum);
    }    
};