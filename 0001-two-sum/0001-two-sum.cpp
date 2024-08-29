class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //make a map to store indx <val,i> ordered
        map<int,int> mpp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int num = nums[i];
            int req = target-num;

            if(mpp.find(req)!=mpp.end()){
                return {mpp[req],i};
            }
            mpp[num]=i;
        }
        return {-1,-1};
        
    }
};