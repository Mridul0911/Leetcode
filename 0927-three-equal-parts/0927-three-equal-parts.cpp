class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        
            int count=0;
            for(auto it:arr)
            {
                    if(it==1)
                    {
                            count++;
                    }
            }
            if(count%3!=0)
            {
                    return {-1,-1};
            }
            int req=count/3;
            int gg=0;
            int zero_count=0;
            int ind=-1;
            for(int i=arr.size()-1;i>=0;i--)
            {
                    if(arr[i]==1)
                    {
                            gg++;
                    }
                    else if(gg==0)
                    {
                            zero_count++;
                    }
                    if(gg==req)
                    {
                            ind=i;
                            break;
                    }
            }
            
            int saved_zero=zero_count;
            gg=0;
            int ind1=-1;
            for(int i=0;i<arr.size();i++)
            {
                    if(arr[i]==1)
                    {
                          gg++;
                          if(gg==req && zero_count==0)
                          {
                                  ind1=i;
                                  break;
                          }
                    }
                    else if(gg==req)
                    {
                            if(zero_count!=0)zero_count--;
                            if(zero_count==0)
                            {
                                    ind1=i;
                                    break;
                            }
                    }
                    if(gg>req)
                    {
                            return {-1,-1};
                    }
            }
            gg=0;
            zero_count=saved_zero;
            int ind2=-1;
            for(int i=ind1+1;i<ind;i++)
            {
                    if(arr[i]==1)
                    {
                          gg++;           
                          if(gg==req && zero_count==0)
                          {
                                  ind2=i+1;
                                  break;
                          }
                    }
                    else if(gg==req)
                    {
                            if(zero_count!=0)zero_count--;
                            if(zero_count==0)
                            {
                                    ind2=i+1;
                                    break;
                            }
                    }
                    if(gg>req)
                    {
                            return {-1,-1};
                    }
            }
            if(ind1==-1 || ind2==-1)
            {
                    return {-1,-1};
            }
            string s1="";
            string s2="";
            string s3="";
            int flag=0;
            for(int i=0;i<=ind1;i++)
            {
                    if(arr[i]==1)
                    {
                            flag=1;
                    }
                    if(flag)
                    {
                         s1+=to_string(arr[i]);
                    }
            }
            flag=0;
            for(int i=ind1+1;i<=ind2-1;i++)
            {
                    if(arr[i]==1)
                    {
                            flag=1;
                    }
                    if(flag)
                    {
                         s2+=to_string(arr[i]);
                    }
            }
            flag=0;
            for(int i=ind2;i<arr.size();i++)
            {
                    if(arr[i]==1)
                    {
                            flag=1;
                    }
                    if(flag)
                    {
                         s3+=to_string(arr[i]);
                    }
            }
            // cout<<s1<<" "<<s2<<" "<<s3<<endl;
            if(s1==s2 && s2==s3)
            {
                    return {ind1,ind2};
            }
            return {-1,-1};
      }
};