class Solution {
public:
    int consecutiveNumbersSum(int n) {
        set<int> ans;
        for (int i=1; i<=sqrt(n); i++)
        {
        if (n%i == 0)
        {
            if (n/i == i)
                ans.insert(i);
  
            else 
                ans.insert(i);
                ans.insert(n/i);
        }
         }
        int count=0;
        for(auto it:ans)
        {
          //  cout<<it<<" ";
            if(it%2==1)
            {
                count++;
            }
        }
        return count;
    }
};