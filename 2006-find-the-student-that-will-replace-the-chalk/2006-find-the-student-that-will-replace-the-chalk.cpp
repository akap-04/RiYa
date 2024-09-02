class Solution {
public:
  

int chalkReplacer(const std::vector<int>& chalk, int k) {
    // Step 1: Calculate the total chalk needed for one full cycle
    long long totalChalk = 0;
    for (int c : chalk) {
        totalChalk += c;
    }

    // Step 2: Calculate the remaining chalk after completing full cycles
    long long remainingChalk = k % totalChalk;

    // Step 3: Determine which student will replace the chalk
    long long currentChalk = 0;
    for (int i = 0; i < chalk.size(); ++i) {
        currentChalk += chalk[i];
        if (currentChalk > remainingChalk) {
            return i;
        }
    }

    // In theory, we should never reach here, but in case of an error:
    return -1;
}

};