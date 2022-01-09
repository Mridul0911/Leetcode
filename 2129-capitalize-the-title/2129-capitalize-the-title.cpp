class Solution {
public:
    string capitalizeTitle(string title) {
     
        int j=0;
            int n=title.size();
            int i=0;
            while(j<n)
            {
                    int i=j;
                    while(j<n && title[j]!=32)
                    {
                            title[j]=tolower(title[j]);
                            j++;
                    }
                    if(j-i>2)
                    {
                         title[i]=toupper(title[i]);   
                    }
                    j++;
                 }
            return title;
            
            
    }
};