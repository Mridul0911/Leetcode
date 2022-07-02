class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
          int mod=1e9+7;
            sort(horizontalCuts.begin(),horizontalCuts.end());
            sort(verticalCuts.begin(),verticalCuts.end());
            int maxihori=0;
            int maxiverti=0;
                  maxihori=max(h-horizontalCuts.back(),horizontalCuts[0]);
                  maxiverti=max(w-verticalCuts.back(),verticalCuts[0]);
            for(int i=0;i<horizontalCuts.size()-1;i++)
            {
                    maxihori=max(maxihori,horizontalCuts[i+1]-horizontalCuts[i]);
            }
            for(int i=0;i<verticalCuts.size()-1;i++)
            {
                    maxiverti=max(maxiverti,verticalCuts[i+1]-verticalCuts[i]);
            }
            return (long)maxihori*maxiverti%1000000007;
     }
};