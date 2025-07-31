class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<pair<int, int>> score_index;
        vector<string> res(n);
        if(!n)return res;

        for(int i=0;i<n;i++){
           score_index.push_back({score[i],i});
        }
        sort(score_index.rbegin(),score_index.rend());
        for(int i=0;i<n;i++){
            int j=score_index[i].second;
            if(i==0)res[j]=("Gold Medal");
            if(i==1)res[j]=("Silver Medal");
            if(i==2)res[j]=("Bronze Medal");
            if(i>2)res[j]=(to_string(i+1));
            
            
        }

        return res;
    }
};