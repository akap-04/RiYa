class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> ds;
        fn(0,target,candidates,ds,ans);
        return ans;

    }
    void fn(int indx,int t,vector<int>&candidate,vector<int>ds,vector<vector<int>>&ans){
        if(indx==candidate.size()){
            if(t==0){
                ans.push_back(ds);
            }
            return;
        }

        if(candidate[indx]<=t){
            ds.push_back(candidate[indx]);
            fn(indx,t-candidate[indx],candidate,ds,ans);
            ds.pop_back();
        }
        fn(indx+1,t,candidate,ds,ans);
    }
};