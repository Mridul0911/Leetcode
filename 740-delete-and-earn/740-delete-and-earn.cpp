class Solution {
public:
 
int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> m(n,0);
        for(int i : nums){
            m[i]+=i;
        }
        for(int i=2;i<n;i++){
            m[i]= max(m[i]+(m[i-2]),m[i-1]);
        }
        
//         int one = m[0];
//         int two = max(one,m[1]);
        
//         for(int i=2;i<n;i++){
//             int cur = max(two,one+m[i]);
//             one=two;
//             two=cur;
//         }
        
        return m[10000];
        
    }
};