class Solution {
public:
         // vector<int> freq(26,-1);
         //    for(int i=0;i<s.size();i++)
         //    {
         //            freq[s[i]-'a']=i;
         //    }
         //    // for(auto i:freq)
         //    // {
         //    //         cout<<i<<endl;
         //    // }
         //   vector<int> ans;
         //    int j=0;
         //    int curr=0;
         //    for(int i=0;i<s.size();i++)
         //    {
         //            j=max(j,freq[s[i]-'a']);
         //            if(i==j)
         //            {
         //                    ans.push_back(i-curr);
         //                    curr=i+1;
         //            }
         //    }
         //    for(int i=0;i<ans.size();i++)
         //    {
         //            ans[i]=ans[i]+1;
         //    }
         //        return ans;    
    vector<int> partitionLabels(string S) {
        vector<vector<int>> intervals(26, vector<int>(2,-1));
        vector<int> res;
        for(int i=0;i<S.size();i++){
            if(intervals[S[i]-'a'][0] == -1) intervals[S[i]-'a'][0] = i;
            intervals[S[i]-'a'][1] = i;
        }
            
              vector<vector<int>> ans;
            sort(intervals.begin(),intervals.end());
          
            vector<int> th=intervals[0];
            
            for(auto it:intervals)
            {
               if(th[1]>=it[0])
               {
                    th[1]=max(th[1],it[1]);   
               }
                    else
                    {
                            ans.push_back(th);
                            th=it;
                    }
           } 
            ans.push_back(th);
            
            for(auto i:ans)
            {
                    if(i[0]==-1 || i[1]==-1) continue;
                  
                    res.push_back(i[1]-i[0]+1);
                    
            }
            return res;
     }
};