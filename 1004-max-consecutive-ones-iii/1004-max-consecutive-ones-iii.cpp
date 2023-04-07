class Solution {
public:
    int longestOnes(vector<int>& answerKey, int k) {
        int count=0;
        int ans=INT_MIN;
        int left=0;
        for(int i=0;i<answerKey.size();i++)
        {
            if(answerKey[i]==0)
            {
                count++;
            }
            //cout<<count<<endl;
            while(count>k){
              //  cout<<"HELLO"<<endl;
                if(answerKey[left]==0)
                {
                    count--;
                }
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
    
};