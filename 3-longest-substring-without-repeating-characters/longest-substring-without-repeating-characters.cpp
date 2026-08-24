class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            string temp = "";

            for (int j = i; j < s.length(); j++) {

                if (temp.find(s[j]) != string::npos) {
                    break;
                }

                temp += s[j];

                if (temp.length() > ans) {
                    ans = temp.length();
                }
            }
        }

        return ans;
    }
};