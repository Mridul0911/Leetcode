class NumArray {
    int bit[30005]={};
    int sum(int i){
        i=i+1;
        int s=0;
        for(;i>0;i-=(i&(-i))){
            s+=bit[i];
        }
        return s;
    }
    
    void _update(int i,int val){
        i=i+1;
        for(;i<30005;i+=(i&(-i))){
            bit[i]+=val;
        }
    }
    
public:
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            _update(i,nums[i]);
        }
    }
    
    void update(int index, int val) {
        
        _update(index,val-sum(index)+sum(index-1));
    }
    
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */