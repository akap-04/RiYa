class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
         k = k%n; 
         int d = n-k;//d left rotn
        reverse(nums.begin(),nums.begin()+d);
        reverse(nums.begin()+d,nums.end());
        reverse(nums.begin(),nums.end());
    }
};