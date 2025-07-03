class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int total=0;
    if(startPos[0]!=homePos[0]){
        if(startPos[0]<homePos[0]){
            for(int i=startPos[0]+1;i<=homePos[0];i++){
                total+=rowCosts[i];
            }
        }else{
            for(int i=startPos[0]-1;i>=homePos[0];i--){
                total+=rowCosts[i];
            }

        }
    }
    if(startPos[1]!=homePos[1]){
        if(startPos[1]<homePos[1]){
            for(int i=startPos[1]+1;i<=homePos[1];i++){
                total+=colCosts[i];
            }
        }else{
            for(int i=startPos[1]-1;i>=homePos[1];i--){
                total+=colCosts[i];
            }

        }
    }


        return total;
        
    }
};