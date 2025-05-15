class Solution {
public:
    int minsubarr(vector<int>& arr ,int k){
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        if(k<0) return 0;

        while(r < arr.size()){
            sum+=arr[r];
            while(sum>k){
                sum=sum-arr[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int ans = minsubarr(nums,goal)-minsubarr(nums,goal-1);
       return ans;
    }
};