class Solution {
public:
    void nextPermutation(vector<int>& nums) {
          int n = nums.size();
    int indx = -1;

    // Step 1: Find the largest index i such that nums[i] < nums[i + 1]
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            indx = i;
            break;
        }
    }

    // If no such index exists, reverse the entire array to get the smallest permutation
    if (indx == -1) {
        reverse(nums.begin(), nums.end());
        return; // We are done
    }

    // Step 2: Find the largest index j greater than indx such that nums[indx] < nums[j]
    for (int i = n - 1; i > indx; i--) {
        if (nums[i] > nums[indx]) {
            swap(nums[i], nums[indx]);
            break;
        }
    }

    // Step 3: Reverse the sequence from indx + 1 to end to get the next permutation
    reverse(nums.begin() + indx + 1, nums.end());
        /*int n = nums.size();
        int indx = -1;
        for(int i = n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                indx = i;
                break;
            }
        }

        if(indx==-1){
            reverse(nums.begin(),nums.end());
    }

        for(int i=n-1; i>=indx ; i--){
            if(nums[i]>nums[indx]){
                swap(nums[i],nums[indx]);
                break;
            }
        }
        
        reverse(nums.begin()+indx+1,nums.end());*/

     
    }
};