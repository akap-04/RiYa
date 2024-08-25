class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int total = 0;
    int length = s.length();
    
    for (int i = 0; i < length; ++i) {
        // Get the value of the current Roman numeral
        int current = romanMap[s[i]];
        
        // If it's not the last character and the next character is greater than the current one
        if (i + 1 < length && romanMap[s[i]] < romanMap[s[i + 1]]) {
            // Subtract current value because it's part of a subtractive combination
            total -= current;
        } else {
            // Otherwise, add the current value
            total += current;
        }
    }
    
    return total;
    }
};