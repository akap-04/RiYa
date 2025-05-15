class Solution {
public:

        int minsubarr(vector<int>& arr ,int k){
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        if(k<0) return 0;

        while(r < arr.size()){
            sum+=(arr[r]%2);
            while(sum>k){
                sum=sum-(arr[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = minsubarr(nums,k)-minsubarr(nums,k-1);
       return ans;
    }
};