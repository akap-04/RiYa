class Solution {
public:

    bool dayPos(vector<int>& arr, int day, int m, int k){
        int cnt=0;
        int numBlooms=0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                cnt++;
            }else{
                numBlooms+=cnt/k;
                cnt=0;
            }
        }
        numBlooms+=cnt/k;
        return (numBlooms>=m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(bloomDay[i],mini);
            maxi=max(bloomDay[i],maxi);
        }
        int low=mini;
        int high=maxi;

        while(low<=high){
            int mid=(low+high)/2;
            if(dayPos(bloomDay,mid,m,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
        
    }
};