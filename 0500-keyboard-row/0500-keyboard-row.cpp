class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> output; //empty array which will be updated acc top ans
        unordered_map<char,int> rows({
            {'z',1},
            {'x',1},
            {'c',1},
            {'v',1},
            {'b',1},
            {'n',1},
            {'m',1},
            {'a',2},
            {'s',2},
            {'d',2},
            {'f',2},
            {'g',2},
            {'h',2},
            {'j',2},
            {'k',2},
            {'l',2},
            {'q',3},
            {'w',3},
            {'e',3},
            {'r',3},
            {'t',3},
            {'y',3},
            {'u',3},
            {'i',3},
            {'o',3},
            {'p',3},
           

        });

        int startingNum;
       
        for(string word:words){
            startingNum = rows[tolower(word[0])];
            bool oneRow = true;

            for(int i=0;i<word.size();i++){
                if(rows[tolower(word[i])] != startingNum){
                    oneRow = false;
                    break;
                }
            }

            if (oneRow) output.push_back(word);
        }
        return output;
        
    }
};