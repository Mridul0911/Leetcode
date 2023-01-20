class Solution {
public:
    vector<double> getAllAns(int st,int end,vector<int> &a) {
        vector<double> ans;
        if(st>end) return ans;
        if(st==end){
            ans.push_back(a[st]);
             return ans;
        }
        for(int i=st;i<end;i++) {
            vector<double> a1=getAllAns(st,i,a);
            vector<double> a2=getAllAns(i+1,end,a);
            for(int j=0;j<a1.size();j++) {
                for(int k=0;k<a2.size();k++) {
                    ans.push_back(a1[j]+a2[k]);
                    ans.push_back(a1[j]-a2[k]);
                    ans.push_back(a1[j]*a2[k]);
                    if(a2[k]) ans.push_back(a1[j]/a2[k]);
                }
            }
        }
        return ans;
    }
    bool judgePoint24(vector<int>& cards) {
       sort(cards.begin(),cards.end());
        do{  
            for(auto it:cards)    
            {
                    cout<<it<<" ";
            }
                cout<<endl;
            vector<double> ans=getAllAns(0,3,cards);
            for(int i=0;i<ans.size();i++) {
                if(abs(ans[i]-24)<=(double)1e-9) {
                    return true;
                }
            }
        }while(next_permutation(cards.begin(), cards.end()));
      return false;
    }
};  