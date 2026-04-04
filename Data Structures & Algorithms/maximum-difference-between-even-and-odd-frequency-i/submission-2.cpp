class Solution {
public:
    int maxDifference(string s) {
        int charCount[26] = {0};

        // 1. Count frequencies
        for (char c : s)
            charCount[c - 'a']++;
        
        // We want the Largest Odd and Smallest Even
        int maxOdd = 0; 
        int minEven = INT_MAX;

        // 2. Iterate through counts
        for (const int count : charCount) { 
            if (count == 0)
                continue;

            if (count % 2 != 0) 
                maxOdd = max(maxOdd, count);
            else 
                minEven = min(minEven, count);
        }
        
        return maxOdd - minEven;
    }
};
