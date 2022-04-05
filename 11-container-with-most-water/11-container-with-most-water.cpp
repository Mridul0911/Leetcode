class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
            int j=height.size()-1;
            int ans=0;
            int finalans=INT_MIN;
            while(i<j)
            {
                 //cout<<"HELLO";               
                   ans=(j-i)*min(height[i],height[j]);
                    finalans=max(finalans,ans);
                    if(height[i]>height[j])
                    {
                            j--;
                    }
                    else
                    {
                            i++;
                    }
                    
            }
            return finalans;
    }
};