class Solution {
public:

    int rob2(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0],prev2=0;
        for(int i=0;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=prev;

            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> arr1(nums.begin()+1,nums.end());    
        vector<int> arr2(nums.begin(),nums.end()-1);
         
        return max(rob2(arr1),rob2(arr2));
        
    }
};