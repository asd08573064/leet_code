class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int dp[nums.size()+1];
				// only to store the path, used when we nee to reconstruct the 
				// answer sequence
        int cnt[nums.size()+1]; 
				// cnt counts the answer sequence length
				// with a sorted array cnt[i] = cnt[j]+1
				// where dp[j] is the longest sequence and i % j == 0
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            cnt[i] = 1;
            dp[i] = -1;
        }
        int max_len = -1;
        int dp_index = 0;
        for(int i=0;i<nums.size();i++){
            int max = -1;
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0 && max < cnt[j]){
                    max = cnt[j];
                    dp[i] = j;
                    cnt[i] = cnt[j]+1;
                    if(cnt[i] > max_len){
                        max_len = cnt[i];
                        dp_index = i;
                    } 
                }
            }
        }
        while(dp_index != -1){
            ans.push_back(nums[dp_index]);
            dp_index = dp[dp_index];
        }
        return ans;
    }
};