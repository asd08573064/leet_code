class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pos = nums[0]; // ans[i] the minimun product that ends with nums[i]
        int neg = nums[0]; // neg[i] the minimun product that ends with nums[i]
        int ans = nums[0];
       
        for(int i = 1; i < nums.size();i++){
            if(nums[i] < 0){ // if times with negative number, then the largest will be the smallest, the least will be the largest
                int tmp = pos;
                pos = neg;
                neg = tmp;
            }
						// pos[i] will be num[i] itself or num[i] * pos
            pos = max(nums[i], pos*nums[i]);
						// same as neg
            neg = min(nums[i], neg*nums[i]);
            
            if(ans < pos) ans = pos;
        }
        return ans;
    }
};_