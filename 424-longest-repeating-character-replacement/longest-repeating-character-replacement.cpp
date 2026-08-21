class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};

        int left = 0;
        int maxCount = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            count[s[right] - 'A']++;

            maxCount = max(maxCount, count[s[right] - 'A']);
            int changes = (right - left + 1) - maxCount;
            while (changes > k) {
                count[s[left] - 'A']--;
                left++;
                changes = (right - left + 1) - maxCount;
            }

            ans = max(ans, right - left + 1);
        }

        return ans; 
    }
};