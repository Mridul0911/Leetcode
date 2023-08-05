class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        bool firstRow=false;
        bool firstCol=false;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(a[i][j]==0)        
                {
                    if(i==0) firstRow=true;
                    if(j==0) firstCol=true;
                    a[i][0]=0;
                    a[0][j]=0;
                }
            }
        }
        for(int i=1;i<a.size();i++)
        {
            for(int j=1;j<a[i].size();j++)
            {
                if(a[i][0]==0 || a[0][j]==0)
                {
                    a[i][j]=0;
                }
            }
        }
        if(firstRow)
        {
            for(int i=0;i<a[0].size();i++)
            {
                a[0][i]=0;
            }
        }
        if(firstCol)
        {
            for(int i=0;i<a.size();i++)
            {
                a[i][0]=0;
            }
        }
    }
};