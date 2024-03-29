//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
        // code here
        for(int i=1;i<arr.size();i++)
        {
            arr[i]+=arr[i-1];
        }
        int sum=arr[N-1];
        vector<int> ans;
        for(int i=1;i*i<=sum;i++)
        {
            if(sum%i==0)
            {
                ans.push_back(i);
                if(i!=sum/i)
                {
                    ans.push_back(sum/i);
                }
            }
        }
        sort(ans.rbegin(),ans.rend());
        int final_ans=1;
        for(auto it:ans)
        {
            int count=0;
            for(int i=0;i<N;i++)
            {
                if(!(arr[i]%it))
                {
                    count++;
                }
            }
            if(count>=K)
            {
                final_ans=it;
                break;
            }
        }
        return final_ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends