class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!= goal.length()) return false;

        std::string str=s+s;

        return str.find(goal) != std::string::npos;
       /* for(int i=0; i<str.length();i++){
            if(str[i]==goal[0]){
                std::string checkstr=str.substr(i,goal.length()+1);
                if(goal==checkstr){
                    return true;
                }
            }
        }
        return false;*/
    }
};