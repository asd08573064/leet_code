class Solution {
public:
    int dp[503][503];
    int solver(int i, int j, vector<int>& nums){
        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i+1; k < j; k++)
             dp[i][j] = max(dp[i][j], (solver(i, k, nums) + solver(k, j, nums) + nums[i] * nums[j] * nums[k]));
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int i = 0; i < 503; i++){
            for(int j = 0; j < 503; j++){
                dp[i][j] = -1;
            }
        }
        return solver(0,nums.size()-1, nums);
    }
};