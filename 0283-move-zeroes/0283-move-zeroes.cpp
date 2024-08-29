class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n = nums.size();
        int j = 0;

        //finding first 0
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        //putting 0 s to end
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0 && nums[j]==0){
                /*int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;*/
                std::swap(nums[i],nums[j]);

                j++;
            }
            
        }


    }
};