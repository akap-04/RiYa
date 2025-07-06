class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> freq;
        for(auto it:arr) freq[it]++;
        int res=-1;
        for(auto [i,cnt]:freq){
            if(i==cnt) res=max(i,res);
        }
        return res;


    }
};