class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 ;
        int r = 0 ;
        int zeros = 0 ; 
        int maxlen = 0 ;

        while(r<nums.size()){
            if(nums[r]==0) zeros++;
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                   
                }
                 l++;
            }
           
            int len = r-l+1;
            maxlen=max(maxlen,len);
            r++;
            
        }
        return maxlen;

/*        while(r<nums.size()){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0){
                    zeros--;
                   
                }  
                 l++;  
            }
            
                int len = l - r + 1 ;
                maxlen = max(len,maxlen);
                r++;
            
        }
      return maxlen;  */
     /* while (r < nums.size()) {
        // Expand the window by including the right boundary element
        if (nums[r] == 0) {
            zeros++;
        }
        
        // Shrink the window from the left if the number of zeros exceeds k
        while (zeros > k) {
            if (nums[l] == 0) {
                zeros--;
            }
            l++;
        }
        
        // Calculate the length of the current valid window and update maxlen
        int len = r - l + 1;
        maxlen = max(maxlen, len);
        
        // Move the right boundary of the window to the right
        r++;
    }
    return maxlen;*/
    }
};