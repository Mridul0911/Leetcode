class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<long long int,vector<long long int> > q;
        long long int sum=0;
        for(int i=0;i<target.size();i++)
        {
            q.push(target[i]);
            sum+=target[i];
        }
        while(!q.empty())
        {
            long long int n=q.top();
            q.pop();
            if(n==1) return true;
            long long int res=sum-n;
            if(res==0) return false;
            if(res==1) return true;
            if(res>=n) return false;
            res=n%res;
            if(res==0) return false;
            sum-=(n-res);
            q.push(res);
        }
        return true;
        
        
        
        
        
        
    }
};