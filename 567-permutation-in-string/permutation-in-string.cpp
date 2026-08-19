class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int n = s1.length();
        int m = s2.length();
        if (n > m)
            return false;
        for (int i = 0; i <= m - n; i++) {
            vector<int> a(26, 0);
            vector<int> b(26, 0);
            
            for (int j = 0; j < n; j++) {
                a[s1[j] - 'a']++;
                b[s2[i + j] - 'a']++;
            }
            if (a == b)
                return true;
        }
        return false;
    }
};