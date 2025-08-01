class Solution {
public:
    bool checkValidString(string s) {
        int curr=0,cnt=0;
        for(char c:s){
            if(c=='('){
                curr++,cnt++;
            }else if(c==')'){
                curr=max(curr-1,0);
                cnt--;
            }else{
                curr=max(curr-1,0);
                cnt++;
            }
            if(cnt<0)return false;
        }

        return curr==0;

    }
};