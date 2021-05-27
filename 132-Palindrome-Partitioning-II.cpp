class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> check(n + 1, vector<bool>(n+1));
        vector<int> dp(n + 1);
        for(int i = 0; i < n; i++){
            check[i][i] = true;
            if (i > 0)
                check[i][i-1] = true;
            for(int j = i-1; j >= 0; j--){
                check[j][i] = (s[i] == s[j] && check[j+1][i-1]);
            }
        }
        for (int i = 0; i < n ; i++){
            if(check[0][i]){
                dp[i] = 0;
            } else {
                dp[i] = 0x3f3f3f3f;
                for(int j = 0; j < i; j++){
                    if(check[j+1][i]) dp[i] = min(dp[i] ,1 + dp[j]); // sepeate to [0, j], [j+1, i], also we have to ensure [0, i] is minimum
                }
            }
        }
        return dp[n-1];
    }
};