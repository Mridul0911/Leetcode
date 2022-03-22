class Solution {
public:
    string getSmallestString(int n, int k) 
    {
    string s(n,'a');
        int pos=n-1;
        k=k-n;
        while(k>0)
        {
            s[pos]+=min(k,25);
            k-=min(k,25);
            pos--;
        }
        return s;
        
        
        
        
        
    }
};