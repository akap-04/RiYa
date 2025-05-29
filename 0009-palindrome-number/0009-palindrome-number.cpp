class Solution {
public:
    bool isPalindrome(int x) {
        string str=to_string(x);
        int n=str.size();
        int i=0,j=n-1;
        while(j>i){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};