class Solution {
public:
    bool isValid(vector<int> &arr2,int num,int d)
    {
        int low=0;
        int high=arr2.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(abs(arr2[mid]-num)<=d){
                return false;
            }
            else if(arr2[mid]<num){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return true;  
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       sort(arr2.begin(),arr2.end());
            int ans=0;
            for(auto it:arr1)
            {
                    if(isValid(arr2,it,d))
                    {
                            ans++;
                    }
            }
            return ans;
    }
};