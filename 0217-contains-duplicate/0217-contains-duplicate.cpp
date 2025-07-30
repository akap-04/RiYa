class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       /* int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;*/

        unordered_set<int>seen;
        for(int n:nums){
            if(seen.count(n)>0)return true;
            seen.insert(n);
        }
        return false;
    }
};