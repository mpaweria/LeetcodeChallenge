class Solution {
public:
    int lcs(string s1, string s2, int m, int n) {
        vector<int> dp(n+1, 0);

        for(int i = m-1; i >= 0; i--) {
            int prev = 0;
            for(int j = n-1; j >= 0; j--) {
                int temp = dp[j];
                if(s1[i] == s2[j])
                    dp[j] = 1 + prev;
                else
                    dp[j] = max(dp[j], dp[j+1]);
                prev = temp;
            }
        }
        return dp[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        return lcs(text1, text2, m, n);
    }
};