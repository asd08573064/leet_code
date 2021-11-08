class Solution {
public:
    bool canCross(vector<int>& stones) {

        map<int , unordered_set<int>>dp;
        dp[0].insert(1);
        for(int i = 0; i < stones.size(); i++){
            for(auto j:dp[stones[i]]){
                dp[stones[i]+j].insert(j);
                dp[stones[i]+j].insert(j+1);
                if(j-1 > 0)
                    dp[stones[i]+j].insert(j-1);
            }
        }
        return !dp[stones[stones.size()-1]].empty(); 
    }
};