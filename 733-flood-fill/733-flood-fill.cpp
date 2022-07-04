class Solution {
public:
void find(int sr,int sc,int newColor,int n,int m,vector<vector<int>> &image,int curr)
        {
if(sr==n || sr<0 || sc==m || sc<0 || image[sr][sc]!=curr || image[sr][sc]==newColor)
                {
                        return;
                }
        image[sr][sc]=newColor;
        find(sr+1,sc,newColor,n,m,image,curr);
        find(sr,sc-1,newColor,n,m,image,curr);
        find(sr-1,sc,newColor,n,m,image,curr);
        find(sr,sc+1,newColor,n,m,image,curr);
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
            int m=image[0].size();
            
           find(sr,sc,newColor,n,m,image,image[sr][sc]); 
            return image;
            
    }
};