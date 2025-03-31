class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> sums;
        for(int i=0;i<n-1;i++){
            int sum=weights[i]+weights[i+1];
            sums.push_back(sum);
        }

        sort(sums.begin(),sums.end());
        long long minS=0;
        long long maxS=0;

        for(int i=0;i<k-1;i++){
            minS+=sums[i];
            maxS+=sums[n-2-i];
        }
        
        return maxS-minS;
    }
};