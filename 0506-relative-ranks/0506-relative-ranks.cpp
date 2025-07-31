class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
         int n=score.size();
        priority_queue<pair<int,int>> pq;//max heap
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        vector<string> ans(n);
        int pos=1;
        while(!pq.empty()){
            int rank=pq.top().second;
            pq.pop();

            if(pos==1)ans[rank]="Gold Medal";
            else if(pos==2)ans[rank]="Silver Medal";
            else if(pos==3)ans[rank]="Bronze Medal";
            else ans[rank]=to_string(pos);

            pos++;
        }
        return ans;
    }
};