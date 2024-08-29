class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*int xor1=0;
        int xor2=0;
        int N = nums.size();
        //int n = N-1;

        for(int i=0;i<N;i++){
            xor2 = xor2 ^ nums[i]; //arry comp
            xor1 = xor1 ^ (i+1); //numbers except N=nums.size()
        }
        xor1 = xor1^(N+1);
        return xor1^xor2;*/
       
       
       
       int N = nums.size();
        int sum = N*(N+1)/2;
        int s2 = 0;

        for(int i = 0;i<N;i++){
            s2 = s2 + nums[i];
        }
        int mnum = sum - s2;
        return mnum;

    }
};