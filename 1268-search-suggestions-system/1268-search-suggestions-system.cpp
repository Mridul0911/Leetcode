class Solution {
public:
        bool isPrefix(string s1,string s2)
        {
                for(int i=0;i<s1.size();i++)
                {
                        if(s2[i]=='\0')
                        {
                                return false;
                        }
                        if(s1[i]!=s2[i])
                        {
                                return false;
                        }
                }
                return true;
        }
        
        
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
         vector<vector<string>> ans;
      
            sort(products.begin(),products.end());
            for(int i=0;i<searchWord.size();i++)
            {
                  string s=searchWord.substr(0,i+1);
                    int low=0;
                    int high=products.size();
                    low=0;
                    high=products.size();
                    while(low<high)
                    {
                        int mid=(low+high)/2;
                        if(products[mid]>=s)
                        {
                                    high=mid;
                        }
                        else
                        {
                            low=mid+1;
                        }
                    }
                    vector<string> ans1;
                    int count=0;
                  //  cout<<low<<endl;
                    for(int j=low;j<products.size();j++)
                    {
                            if(count==3)  break;
                            if(products[j].find(s)==0)
                            {
                                 ans1.push_back(products[j]);
                                    count++;
                            }
                            else
                            {
                                    break;
                            }
                    }
                    ans.push_back(ans1);
                    
            
            }
            return ans;
            
            
        
    }
};