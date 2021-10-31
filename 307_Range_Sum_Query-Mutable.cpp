class NumArray {
private: 
    int tree[120001] = {0};
    int len = 0;
    vector<int> tmp;
public:
    NumArray(vector<int>& nums) {
        len = nums.size();
        tmp = nums;
        create(1,0,nums.size()-1,nums);
    }
    
    int create(int index ,int left, int right, vector<int>& nums){
        if (left == right){
            tree[index] = nums[left];
        }
        else{
            int mid = (left + right)/2;
            int left_v = create(index*2, left, mid, nums);
            int right_v = create(index*2+1, mid+1, right, nums);
            tree[index] = left_v + right_v;
        }
        return tree[index];  
    }
    
    void update(int index, int val) {
        if (left == right){
            treep[index] = nums[left];
            return nums[left];
        }
        int mid = (left + right)/2;
        update(index*2, left, mid, nums);
        update(index*2+1, mid+1, right, nums);
        tree[index] = 
    }
    
    void insert(int index, int id, int val, int left, int right){
      
    }
    
    int sumRange(int left, int right) {

    }
    
    int find(int index, int left, int right, int now_l, int now_r){
     
    }
};     