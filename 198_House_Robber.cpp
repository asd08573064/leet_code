class Solution {
public:
    int rob(vector<int>& nums) {
        int *with = new int[nums.size()];
        int *without = new int[nums.size()];
        if(nums.size() > 2){
            with[0] = nums[0];
            with[1] = nums[1];
            without[0] = 0;
            without[1] = nums[0];
        }
        else{
            if(nums.size() == 2)
                return max(nums[0],nums[1]);
            return nums[0];
        }
        for(int i = 2; i < nums.size(); i++){
            with[i] = max(nums[i]+without[i-1], with[i-2]+nums[i]);
            without[i] = max(with[i-1], without[i-1]);
        }
        int ans = max(without[nums.size()-1], with[nums.size()-1]);
        return ans;
    }
};
