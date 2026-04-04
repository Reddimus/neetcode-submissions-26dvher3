class Solution {
public:
    int lengthOfLastWord(string s) {
        // Find last word end & skip end of line whitespace
        int r = s.length() - 1;
        for (; r >= 0 && s[r] == ' '; --r);
         
        // Fine last word start 
        int l = r;
        for (; l >= 0 && s[l] != ' '; --l);
        return r - l;
    }
};