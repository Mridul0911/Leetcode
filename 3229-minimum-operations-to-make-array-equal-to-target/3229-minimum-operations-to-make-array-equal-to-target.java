class Solution {
    public long minimumOperations(int[] nums, int[] target) {
        long total = (int)Math.abs(nums[0]-target[0]);
        long cur = total;
        int neg = (nums[0] < target[0] ? 1 : 0);
        for(int i=1;i<nums.length;i++){
            int diff = (int)Math.abs(nums[i]-target[i]);
            int curNeg = (nums[i] < target[i] ? 1 : 0);
            if(curNeg == neg){
                if(diff > cur){
                    total += (diff-cur);
                }
                cur = diff;
            }else{
                total += diff;
                neg = curNeg;
                cur = diff;
            }
        }
        return total;
    }
}