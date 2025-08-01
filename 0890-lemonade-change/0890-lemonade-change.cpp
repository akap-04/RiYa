class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5=0,b10=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5)b5+=1;
            else if(bills[i]==10){
                if(b5!=0){
                    b5-=1;
                    b10+=1;
                }else{
                    return false;
                }
            }else{
                if(b10!=0 && b5!=0){
                    b5-=1;
                    b10-=1;
                }
                else if(b5>=3){
                    b5-=3;
                }
                else{
                    return false;
                }
            }

        }
        return true;
    }
};