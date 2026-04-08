class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++) {
            // Check if character is uppercase
            if (s[i] >= 'A' && s[i] <= 'Z') {
                // Convert to lowercase
                s[i] = s[i] - 'A' + 'a';
            }
        }
        return s;
    }
};