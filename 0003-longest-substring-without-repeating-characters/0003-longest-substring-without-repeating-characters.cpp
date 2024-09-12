class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
       int n = s.length();
       vector<int> hash(128,-1);//char index
       int l=0;
       int r=0;
       int maxlen=0;

       while(r<n){
        //present in map
        if(hash[s[r]]!=-1){
            //check for pos of l
            if(hash[s[r]] >= l){
                l = hash[s[r]]+1;
            }
        }
        int len = r-l+1;
        maxlen = max(len,maxlen);
        hash[s[r]]=r;
        r++;
       }
       return maxlen;

    }
};